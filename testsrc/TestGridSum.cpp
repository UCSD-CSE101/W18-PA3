// Tester for PA3 GridSum
//
// DO NOT MODIFY

#ifndef __TEST_GRID_SUM_CPP__
#define __TEST_GRID_SUM_CPP__

#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

#include "TwoD_Array.hpp"
#include "GridSum.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);

    // grab the grid size
    int size;
    std::string strSize;
    if (getline(input, strSize)) {
        std::stringstream stream(strSize);
        stream >> size; 
    }
    else {
        std::cerr << "Unable to open file '" << argv[1] << "'" << std::endl;
        exit(1);
    }

    TwoD_Array<int> grid(size, size);

    for (int i = 0; i < size; i++) {
        std::string row;
        if (getline(input, row)) {
            std::stringstream stream(row);
            for (int j = 0; j < size; j++) {
                stream >> grid.at(i, j);
            }
        }
        else {
            std::cerr << "Input file was incorrectly formatted per size" << std::endl;
            exit(1);
        }
    }

    GridSum gridsum(grid);

    std::vector<std::tuple<int,int,int,int,int>> results;
    std::string query;

    while (getline(input, query)) {
        std::stringstream stream(query);
        int x1, x2, y1, y2;
        stream >> x1;
        stream >> y1;
        stream >> x2;
        stream >> y2;
        if (x1 >= size || x2 >= size || y1 >= size || y2 >= size ||
            x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
            std::cerr << "Input file has a malformed query" << std::endl;
            exit(1);
        }
        results.push_back(
                std::make_tuple(x1, y1, x2, y2, gridsum.query(x1, y1, x2, y2)));
    }

    for (auto it = results.begin(); it != results.end(); ++it) {
        std::cout << "Grid sum for (" << std::get<0>(*it) << ","
                  << std::get<1>(*it) << ") to ("  << std::get<2>(*it)
                  << "," << std::get<3>(*it) << "): " << std::get<4>(*it) << "\n";
    }
    
    return 0;
}

#endif
