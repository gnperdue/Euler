#include "NumberSpiral.h"
#include <iostream>

NumberSpiral::NumberSpiral() : 
  width(1)
{
}

NumberSpiral::NumberSpiral(unsigned init) : 
  width(init)
{
	if (width % 2 != 1) {
		std::cerr << "Width must be odd! Adding one." << std::endl;
	}
}

void NumberSpiral::calculate() 
{
	for (unsigned ring = width; ring > 1; ring -= 2) {
		unsigned step = ring - 1;
		unsigned val  = ring * ring;
		topRightToBottomLeft.push_back( val );
    val -= step;
    topLeftToBottomRight.push_back( val );
    val -= step;
    topRightToBottomLeft.push_back( val );
    val -= step;
    topLeftToBottomRight.push_back( val );
  }
  topLeftToBottomRight.push_back(1);
  topRightToBottomLeft.push_back(1);
}

unsigned NumberSpiral::getTopLeftToBottomRightSum() const
{
  return getVectorSum(topLeftToBottomRight);
}
unsigned NumberSpiral::getTopRightToBottomLeftSum() const
{
  return getVectorSum(topRightToBottomLeft);
}
unsigned NumberSpiral::getVectorSum(const std::vector<unsigned>& v) const
{
  unsigned sum = 0;
  for (auto n : v) {
    sum += n;
  }
  return sum;
}

