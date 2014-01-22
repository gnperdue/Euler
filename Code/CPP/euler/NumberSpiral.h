#ifndef NumberSpiral_h
#define NumberSpiral_h

#include <vector>

class NumberSpiral {

  private:
    unsigned width;
    std::vector<unsigned> topLeftToBottomRight;
    std::vector<unsigned> topRightToBottomLeft;

  public:
    NumberSpiral();
    NumberSpiral(unsigned width);
    ~NumberSpiral() {}
    NumberSpiral& operator=(const NumberSpiral&) = delete;
    NumberSpiral(const NumberSpiral&) = delete;

		void     calculate();
		unsigned getTopLeftToBottomRightSum() const;
		unsigned getTopRightToBottomLeftSum() const;
		unsigned getVectorSum(const std::vector<unsigned>& v) const;
};


#endif
