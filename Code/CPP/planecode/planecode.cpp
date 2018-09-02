#include <iostream>  // NOLINT(readability/streams)
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>

int main(int argc, char * argv[]) {

  uint64_t run = 117200; // 6 digits
  uint64_t subrun = 1;   // max is 9999
  uint64_t gate = 1;     // max is 9999
  uint64_t slice = 1;

  std::stringstream ss;
  ss << std::setfill('0') << std::setw(6) << run;
  ss << std::setfill('0') << std::setw(4) << subrun;
  ss << std::setfill('0') << std::setw(4) << gate;
  ss << std::setfill('0') << std::setw(2) << slice;

  const std::string& tmp = ss.str();
  std::cout << tmp << std::endl;

  uint64_t eventid = strtoull(tmp.c_str(), NULL, 10);
  std::cout << eventid << std::endl;

  return 0;
}

