/**
 * @file networkx.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef INCLUDE_NETWORKX_H_
#define INCLUDE_NETWORKX_H_

#include <network.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>

using std::string;

class Station {
 public:
  Station(string current_, string goal_) {
    current_idx = this->get_station(current_);
    goal_idx = this->get_station(goal_);
    current = network[current_idx];
    goal = network[goal_idx];
    charge = 320;
    reached = false;
    visited = {current_idx};
    bts = 0;
    path = {};
  }

  double get_dist(row station) {
    // Calculate the distance between two stations
    auto dist = std::sin(to_rad(current.lat)) * std::sin(to_rad(station.lat)) +
                std::cos(to_rad(current.lat)) * std::cos(to_rad(station.lat)) *
                    std::cos(to_rad(current.lon - station.lon));

    return e_rad * std::acos(dist);
  }

  double get_dist(row station_1, row station_2) {
    auto dist =
        std::sin(to_rad(station_1.lat)) * std::sin(to_rad(station_2.lat)) +
        std::cos(to_rad(station_1.lat)) * std::cos(to_rad(station_2.lat)) *
            std::cos(to_rad(station_1.lon - station_2.lon));

    return e_rad * std::acos(dist);
  }

  double to_rad(double angle) { return angle * M_PI / 180; }

  int get_station(string station) {
    int i{};
    row station_;

    while (network[i].name != station) {
      i++;
    }
    return i;
  }

  bool is_visited(int node_idx) {
    return (std::find(visited.begin(), visited.end(), node_idx) !=
            visited.end());
  }

  bool is_valid(int node_idx) {
    if (get_dist(network[node_idx]) > full) {
      return false;
    } else if (is_visited(node_idx)) {
      return false;
    } else {
      return true;}
  }

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
    if (charge_time != 0) {
      std::cout << charge_time << ",";
    }

    x.push_back(current.lat);
    y.push_back(current.lon);

    bts += next_distance / speed;

    path.push_back(current);

    bts += charge_time;
    charge -= next_distance;
    current = network[next_idx];
    current_idx = next_idx;

    if (!is_visited(next_idx)) {
      visited.push_back(next_idx);
    }
  }

  void get_path() {
    find_next();
    move_next();
    if (!reached) {
      get_path();
    }
  }

  void find_next() {
    int next_ = -1;
    double ctg = 1e+10;
    for (int i{}; i < static_cast<int>(network.size()); i++) {
      if (is_valid(i)) {
        auto ctg_ =
            (get_dist(network[i], goal)) / speed +
            full / std::max(network[i].rate,
                            current.rate);  //+ get_dist(network[i])/speed;

        if (ctg_ < ctg) {
          ctg = ctg_;
          next_ = i;
        } else {
          continue;
        }
      }
    }

    if (next_ == -1) {
      std::cout << "No valid node found";
      return;
    }

    next_distance = get_dist(network[next_]);
    next_idx = next_;
    if (network[next_idx].name == goal.name) {
      reached = true;
    }
  }

  row current;
  row goal;
  double bts;
  std::vector<double> x;
  std::vector<double> y;
  std::vector<row> path;

 private:
  int current_idx;
  int goal_idx;
  double next_distance;
  int next_idx;
  bool reached;
  std::vector<int> visited;
  int charge;
  const int full = 320;
  const int speed = 105;
  const double e_rad = 6356.752;
};

#endif  // INCLUDE_NETWORKX_H_
