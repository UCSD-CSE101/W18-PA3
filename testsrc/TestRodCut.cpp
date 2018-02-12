// Tester for PA3 LCS
//
// DO NOT MODIFY

#ifndef __TEST_RODCUT_CPP__
#define __TEST_RODCUT_CPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

#include "RodCut.hpp"

int main(int argc, char * argv[]) {
  if(argc != 2){
    std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
    exit(1);
  }

  std::ifstream input(argv[1], std::ios::in);

  // get rod length
  int length;
  std::string strLength;
  if (getline(input, strLength)) {
    std::stringstream stream(strLength);
    stream >> length;
  } else {
    std::cerr<< "Unable to open file '" << argv[1] << "'" << std::endl;
    exit(1);
  }

  int cut;
  int val;
  std::map<int, int> prices;
  std::string raw;
  while (getline(input, raw)) {
    std::stringstream stream(raw);
    stream >> cut;
    stream >> val;
    prices[cut] = val;
  }

  int maxVal = rodcut(prices, length);

  std::cout << "Maximum value cuts: " << maxVal << std::endl;

  return 0;

}

#endif



