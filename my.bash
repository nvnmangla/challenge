#!/bin/bash
conda deactivate
cd ~/Desktop/challenge/build
make
echo "Running Tests"
./test/cpp-test Centralia_WA Port_Orange_FL

echo "Running candidate_solution"
./app/candidate_solution Centralia_WA Port_Orange_FL
cd ..