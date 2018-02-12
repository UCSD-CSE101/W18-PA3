// Tester for PA3 USB
//
// DO NOT MODIFY

#ifndef __TEST_USB_CPP__
#define __TEST_USB_CPP__

#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <vector>

#include "USB.hpp"

int main(int argc, char * argv[]) {
    if (argc != 3) {
        std::cerr << "Invalid number of arguments; expecting 2 for file name and index for usb method" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);

    // grab the usb size
    int USBsize;
    std::string strUSBsize;
    if (getline(input, strUSBsize)) {
        std::stringstream stream(strUSBsize);
        stream >> USBsize; 
    }
    else {
        std::cerr << "Unable to open file '" << argv[1] << "'" << std::endl;
        exit(1);
    }

    std::vector<int> files;
    std::string files_string;

    if (getline(input, files_string)) {
        std::stringstream stream(files_string);
        while (!stream.eof()) {
            int filesize;
            stream >> filesize;
            files.push_back(filesize);
        }
    }
    else {
        std::cerr << "Input file was missing the line for filesizes" << std::endl;
        exit(1);
    }

    if (*argv[2] == '1') {
        std::cout << "Result of find_files_naive: " << find_files_naive(USBsize, files) << std::endl;
    }
    else if (*argv[2] == '2') {
        std::cout << "Result of find_files_memoized: " << find_files_memoized(USBsize, files) << std::endl;
    }
    else if (*argv[2] == '3') {
        std::cout << "Result of find_files_dp: " << find_files_dp(USBsize, files) << std::endl;
    }


    return 0;
}

#endif
