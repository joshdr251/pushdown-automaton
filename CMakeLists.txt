cmake_minimum_required(VERSION 4.3)
project(pushdown_automaton)

set(CMAKE_CXX_STANDARD 20)

add_executable(det_pushdown_automaton det_pushdown_automaton.cpp)
add_executable(nondet_pushdown_automaton nondet_pushdown_automaton.cpp)
