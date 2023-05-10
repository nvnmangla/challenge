/**
 * @file station.h
 * @author Naveen Mangla (namangla@termail.umd.edu)
 * @brief Station class for implementations
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
#include <cassert>
#include <cmath>
#include <memory>
#include <string>
#include <vector>

using std::string;

extern int my_argc;
extern char** my_argv;
class Station {
 public:
  /**
   * @brief Construct a new Station object
   *
   * @param current_ starting station
   * @param goal_ goal station
   */
  Station(string current_, string goal_);

  /**
   * @brief Calculate distance between current station and next station
   *
   * @param station Next station
   * @return double
   */
  double get_dist(row station);

  /**
   * @brief Calculate distance between two given stations
   *
   * @param station_1
   * @param station_2
   * @return double
   */
  double get_dist(row station_1, row station_2);

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
  int get_station(string station);
  /**
   * @brief Check if the Station is visited
   *
   * @param node_idx index of station to check
   * @return true
   * @return false
   */
  bool is_visited(int station_idx);
  /**
   * @brief Check if the station is valid to move or not,
   * It will make sure that the station is not visited and comes in full
   * charging range
   * @param station_idx
   * @return true
   * @return false
   */
  bool is_valid(int station_idx);

  /**
   * @brief Move to the next station
   *
   */
  void move_next();

  /**
   * @brief Get the optimal path
   *
   */
  void get_path();

  /**
   * @brief Find the next possible station
   */
  void find_next();

  double bts;    // total time taken (charging_time + travelling_time)
  bool reached;  // Flag, if the goal is reached
  std::string path;

 private:
  row current;                    // current station
  row goal;                       // goal station
  int current_idx;                // index of current station
  int goal_idx;                   // index of goal station
  double next_distance;           // distnce to next station
  int next_idx;                   // index of next station
  std::vector<int> visited;       // Vector of visited stations
  double charge;                  // charge of battery
  const double full = 320.00;     // total charge
  const int speed = 105;          // speed of the vehicle
  const double e_rad = 6356.752;  // Radius of Earth in Km
};

#endif  // INCLUDE_STATION_H_
