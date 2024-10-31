#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Vehicle.hpp"

std::vector<std::vector<int>> loadMatrix(const std::string &fileName);

std::vector<Package> loadPackages(const std::string &fileName);

std::vector<int> findShortestPaths(const std::vector<std::vector<int>>& matrix, int start);

