#ifndef CODE_CPP_EULER_TRIANGULARNUMBER_H_
#define CODE_CPP_EULER_TRIANGULARNUMBER_H_

#include <vector>

class TriangularNumber {

  private:  // NOLINT(whitespace/indent)
    uint64_t initialValue;
    uint64_t triangularNumber;
    void calcTriangle();

  public:  // NOLINT(whitespace/indent)
    TriangularNumber();
    explicit TriangularNumber(uint64_t initialValue);
    ~TriangularNumber() {}
    TriangularNumber& operator=(const TriangularNumber&) = delete;
    TriangularNumber(const TriangularNumber&) = delete;

    void set(uint64_t index);
    uint64_t get() const;
    std::vector<uint64_t> factors() const;
};

#endif  // CODE_CPP_EULER_TRIANGULARNUMBER_H_
