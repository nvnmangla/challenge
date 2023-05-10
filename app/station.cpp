/**
 * @file station.cpp
 * @author Naveen Mangla (nmangla@terpmail.umd.edu)
 * @brief Function Definitions for station
 * @version 0.1
 * @date 2023-05-10
 * @copyright Copyright (c) 2023
 * 
 */
#include <network.h>
#include <station.h>

Station::Station(string current_, string goal_) {
  current_idx = this->get_station(current_);
  goal_idx = this->get_station(goal_);
  current = network[current_idx];
  goal = network[goal_idx];
  charge = 320;
  reached = false;
  visited = {current_idx};  // starting visited with current_idx
  next_distance = 0;
  next_idx = 0;
  bts = 0;
}

double Station::get_dist(row station) {
  auto dist = std::sin(to_rad(current.lat)) * std::sin(to_rad(station.lat)) +
              (std::cos(to_rad(current.lat)) * std::cos(to_rad(station.lat)) *
               std::cos(to_rad(current.lon - station.lon)));

  return (e_rad * std::acos(dist)); // Distance in KM
}

double Station::get_dist(row station_1, row station_2) {
  auto dist =
      std::sin(to_rad(station_1.lat)) * std::sin(to_rad(station_2.lat)) +
      (std::cos(to_rad(station_1.lat)) * std::cos(to_rad(station_2.lat)) *
       std::cos(to_rad(station_1.lon - station_2.lon)));

  return e_rad * std::acos(dist); // Distance in KM
}

int Station::get_station(string station) {
  int i{};
  while (network[i].name != station) {
    i++;
  }
  return i;
}

bool Station::is_visited(int station_idx) {
  return (std::find(visited.begin(), visited.end(), station_idx) !=
          visited.end());
}

bool Station::is_valid(int station_idx) {
  if (get_dist(network[station_idx]) > full) {
    return false;
  } else if (is_visited(station_idx)) {
    return false;
  } else {
    return true;
  }
}

void Station::move_next() {
  double charge_time{};

  assert(next_distance <= full && next_distance >= 0);

    
  if ((charge <= next_distance) || (next_idx == goal_idx)) {
    if (network[next_idx].rate > current.rate) {
      charge_time = (next_distance - charge) / current.rate;
      charge = next_distance;
    } else {
      charge_time = (full - charge) / current.rate;
      charge = full;
    }
  }

  assert(charge >= next_distance);

  path += (current.name + ",");
  if (charge_time !=
      0) {  // condition for charge time = 0, this is for starting station

    path += (std::to_string(charge_time) + ",");
  }

  bts += next_distance / speed;  // Travelling time

  bts += charge_time;  // charging time

  // Moving
  charge -= next_distance;

  assert(charge >= 0); 

  current = network[next_idx];
  current_idx = next_idx;

  if (!is_visited(next_idx)) {
    visited.push_back(next_idx);
  }
}

void Station::get_path() {
  find_next();
  move_next();
  if (!reached) {
    get_path();
  } else {
    path += goal.name;
  }
}

void Station::find_next() {
  int next_ = -1;
  double ctg = 1e+10;  // Cost to go
  for (int i{}; i < static_cast<int>(network.size()); i++) {
    if (is_valid(i)) {
      auto ctg_ =  // local cost to go,
          ((get_dist(network[i], goal)) / speed) +
          (full / std::max(network[i].rate, current.rate));

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