cmake_minimum_required(VERSION 3.9)
project(hash_code_2018)

set(CMAKE_CXX_STANDARD 11)

file(COPY input/a_example.in input/b_should_be_easy.in input/c_no_hurry.in input/d_metropolis.in input/e_high_bonus.in DESTINATION input)

add_executable(hash_code_2018 main.cpp headers/Ride.h sources/Ride.cpp headers/Ride.h headers/Point.h sources/Point.cpp headers/Vehicle.h sources/Vehicle.cpp)