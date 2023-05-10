#!/bin/bash
conda deactivate
cd ~/Desktop/challenge/build
make
./app/candidate_solution
cd ..