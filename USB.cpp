// CSE 101 Winter 2018, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __USB_CPP__
#define __USB_CPP__

#include <map>
#include "USB.hpp"
#include "TwoD_Array.hpp"

int find_files_naive(int USBsize, std::vector<int>& files) {
  int min = -1;
  for (auto it = files.begin(); it != files.end(); ++it) {
    if (USBsize == *it) {   // 1 is the minimum number of possible files
      return 1;
    }
    else if (USBsize > *it) {
      // assume per the problem statement that the USB size is always met
      int files_used = find_files_naive(USBsize - *it, files) + 1;
      if (min == -1 || (files_used < min && files_used > 0)) {
        min = files_used;
      }
    }
    // do nothing if file size is larger than the USB size
  }
  return min;
}

std::map<int, int> memoize;
int find_files_memoized(int USBsize, std::vector<int>& files) {
  return 0;
}

int find_files_dp(int USBsize, std::vector<int>& files) {
  return 0;
}
#endif
