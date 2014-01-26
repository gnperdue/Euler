#ifndef DigitSums_h
#define DigitSums_h

#include <vector>

class DigitSums {

  private:
    unsigned number;
    std::vector<unsigned> digits;

  public:
    DigitSums();
    DigitSums(unsigned num);
    ~DigitSums() {};

    void setNumber(unsigned num);
    unsigned getNumber() const;
    std::vector<unsigned> calcDigitsForNumber(unsigned num) const;
    std::vector<unsigned> getDigits() const;
    unsigned getDigitSum() const;
    unsigned getDigitsToPowerSum(unsigned power) const;

};

#endif

