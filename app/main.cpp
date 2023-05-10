/**
 * @file main.cpp
 * @author Naveen Mangla (namangla@termail.umd.edu)
 * @brief main file for implementation
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <network.h>
#include <station.h>

#include <algorithm>
#include <cmath>
#include <vector>

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Error: requires initial and final supercharger names"
              << std::endl;
    return -1;
  }

  std::string initial_charger_name = argv[1];
  std::string goal_charger_name = argv[2];

  Station st(initial_charger_name, goal_charger_name);
  st.get_path();
  std::cout << st.path;
  std::cout << "\nGoal Reached ! Time Taken = " << st.bts << '\n';
  return 0;
}
