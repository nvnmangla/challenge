/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <network.h>
#include <networkx.h>
#include <algorithm>
#include <cmath>
#include <vector>


int main(/*int argc, char** argv*/) {
  Station st("Centralia_WA", "Port_Orange_FL");
  st.get_path();
  std::cout << st.goal.name;
  std::cout << "\nGoal Reached ! Time Taken = " << st.bts << '\n';

  std::vector<float> x_axis, y_axis;
  for (int i = 0; i < static_cast<int>(network.size()); i++) {
    x_axis.push_back(network[i].lat);
    y_axis.push_back(network[i].lon);
  }

  plt::scatter(y_axis, x_axis);
  plt::plot(st.y, st.x, "r-");
  plt::show();

  return 0;
}
