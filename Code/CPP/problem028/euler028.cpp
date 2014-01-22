#include <iostream>
#include <cstdlib>
#include "NumberSpiral.h"

const unsigned default_width = 5;
void usage(const char* prog_name);

int main(int argc, const char *argv[])
{
  unsigned width = default_width;
  if (argc < 2) { 
    usage(argv[0]);
  }
  else {
    width = (unsigned int)strtoul(argv[1],NULL,10);
  }

  NumberSpiral ns(width);
  ns.calculate();
  unsigned topLeftToBottomRight = ns.getTopLeftToBottomRightSum();
  unsigned topRightToBottomLeft = ns.getTopRightToBottomLeftSum();
  std::cout << "topLeftToBottomRight = " << topLeftToBottomRight << std::endl;
  std::cout << "topRightToBottomLeft = " << topRightToBottomLeft << std::endl;
  unsigned diagSum = topLeftToBottomRight + topRightToBottomLeft - 1;
  std::cout << "diagonal sum = " << diagSum << std::endl;
  
  return 0;
}

void usage(const char* prog_name)
{
  std::cout << "Usage: " << prog_name << " ndiag(default is " 
    << default_width << ")" << std::endl;
}

