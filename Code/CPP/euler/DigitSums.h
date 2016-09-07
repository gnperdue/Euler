#ifndef CODE_CPP_EULER_DIGITSUMS_H_
#define CODE_CPP_EULER_DIGITSUMS_H_

#include <vector>
#include <cstdint>

class DigitSums {

  private:  // NOLINT(whitespace/indent)
    uint64_t number;
    std::vector<uint64_t> digits;

  public:   // NOLINT(whitespace/indent)
    DigitSums();
    explicit DigitSums(uint64_t num);
    ~DigitSums() {}

    void setNumber(uint64_t num);
    uint64_t getNumber() const;
    std::vector<uint64_t> calcDigitsForNumber(uint64_t num) const;
    std::vector<uint64_t> getDigits() const;
    uint64_t getDigitSum() const;
    uint64_t getDigitsToPowerSum(uint64_t power) const;
};

#endif  // CODE_CPP_EULER_DIGITSUMS_H_

