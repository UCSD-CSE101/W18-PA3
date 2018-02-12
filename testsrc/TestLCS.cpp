// Tester for PA3 LCS
//
// DO NOT MODIFY

#ifndef __TEST_LCS_CPP__
#define __TEST_LCS_CPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "LCS.hpp"

int main(int argc, char * argv[]){
    if(argc != 2){
        std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
        exit(1);
    }

    std::ifstream input(argv[1], std::ios::in);

    std::string str1;
    std::string str2;

    if(!getline(input, str1) || !getline(input, str2)){
        std::cerr << "Unable to open/parse file '" << argv[1] << "'" << std::endl;
    }

    input.close();

    std::cout << "The LCS is: '" << lcs(str1, str2) << "'" << std::endl;

    return 0;
}

#endif
