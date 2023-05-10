/**
 * @file station.h
 * @author Naveen Mangla (namangla@termail.umd.edu)
 * @brief
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef INCLUDE_STATION_H_
#define INCLUDE_STATION_H_

#include <network.h>

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <vector>

using std::string;

class Station {
 public:
  /**
   * @brief Construct a new Station object
   *
   * @param current_ starting station
   * @param goal_ goal station
   */
  Station(string current_, string goal_) {
    current_idx = this->get_station(current_);
    goal_idx = this->get_station(goal_);
    current = network[current_idx];
    goal = network[goal_idx];
    charge = 320;
    reached = false;
    visited = {current_idx};
    next_distance = 0;
    next_idx = 0;
    bts = 0;
  }

  /**
   * @brief Calculate distance between current station and next station
   *
   * @param station Next station
   * @return double
   */
  double get_dist(row station) {
    auto dist = std::sin(to_rad(current.lat)) * std::sin(to_rad(station.lat)) +
                std::cos(to_rad(current.lat)) * std::cos(to_rad(station.lat)) *
                    std::cos(to_rad(current.lon - station.lon));

    return e_rad * std::acos(dist);
  }

  /**
   * @brief Calculate distance between two given stations
   *
   * @param station_1
   * @param station_2
   * @return double
   */
  double get_dist(row station_1, row station_2) {
    auto dist =
        std::sin(to_rad(station_1.lat)) * std::sin(to_rad(station_2.lat)) +
        std::cos(to_rad(station_1.lat)) * std::cos(to_rad(station_2.lat)) *
            std::cos(to_rad(station_1.lon - station_2.lon));

    return e_rad * std::acos(dist);
  }

  /**
   * @brief Degrees to Radians
   *
   * @param angle angle in degrees
   * @return Angle in radians
   */
  double to_rad(double angle) { return angle * M_PI / 180; }

  /**
   * @brief Get the station index from station-name
   *
   * @param station station-name
   * @return int
   */
  int get_station(string station) {
    int i{};
    while (network[i].name != station) {
      i++;
    }
    return i;
  }

  /**
   * @brief Check if the Station is visited
   *
   * @param node_idx index of station to check
   * @return true
   * @return false
   */
  bool is_visited(int station_idx) {
    return (std::find(visited.begin(), visited.end(), station_idx) !=
            visited.end());
  }

  /**
   * @brief Check if the station is valid to move or not,
   * It will make sure that the station is not visited and comes in full
   * charging range
   * @param station_idx
   * @return true
   * @return false
   */
  bool is_valid(int station_idx) {
    if (get_dist(network[station_idx]) > full) {
      return false;
    } else if (is_visited(station_idx)) {
      return false;
    } else {
      return true;
    }
  }

  /**
   * @brief Move to the next station
   *
   */
  void move_next() {
    double charge_time{};

    if (charge < next_distance || next_idx == goal_idx) {
      if (network[next_idx].rate > current.rate) {
        charge_time = abs(next_distance - charge) / current.rate;
        charge = next_distance;
      } else {
        charge_time = abs(full - charge) / current.rate;
        charge = full;
      }
    }

    std::cout << current.name << ",";
    if (charge_time !=
        0) {  // condition for charge time = 0, this is for starting station
      std::cout << charge_time << ",";
    }

    // For plotting
    x.push_back(current.lat);
    y.push_back(current.lon);

    bts += next_distance / speed;  // Travelling time

    bts += charge_time;  // charging time

    // Moving
    charge -= next_distance;
    current = network[next_idx];
    current_idx = next_idx;

    if (!is_visited(next_idx)) {
      visited.push_back(next_idx);
    }
  }

  /**
   * @brief Get the optimal path
   *
   */
  void get_path() {
    find_next();
    move_next();
    if (!reached) {
      get_path();
    }
  }

  /**
   * @brief Find the next possible station
   *
   */
  void find_next() {
    int next_ = -1;
    double ctg = 1e+10;  // Cost to go
    for (int i{}; i < static_cast<int>(network.size()); i++) {
      if (is_valid(i)) {
        auto ctg_ =  // local cost to go,
            (get_dist(network[i], goal)) / speed +
            full / std::max(network[i].rate, current.rate);

        if (ctg_ < ctg) {
          ctg = ctg_;
          next_ = i;  // updating next station
        } else {
          continue;
        }
      }
    }

    if (next_ == -1) {
      std::cout << "No valid node found";
      return;
    }

    next_distance = get_dist(network[next_]);  // distance to the next station
    next_idx = next_;
    if (network[next_idx].name == goal.name) {
      reached = true;
    }
  }

  row current;  // current station
  row goal;     // goal station
  double bts;   // total time taken (charging_time + travelling_time)
  std::vector<double> x;
  std::vector<double> y;

 private:
  int current_idx;                // index of current station
  int goal_idx;                   // index of goal station
  double next_distance;           // distnce to next station
  int next_idx;                   // index of next station
  bool reached;                   // Flag, if the goal is reached
  std::vector<int> visited;       // Vector of visited stations
  int charge;                     // charge of battery
  const int full = 320;           // total charge
  const int speed = 105;          // speed of the vehicle
  const double e_rad = 6356.752;  // Radius of Earth in Km
};

#endif  // INCLUDE_STATION_H_
