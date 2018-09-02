#ifndef CODE_CPP_EULER_PYTHAGOREANTRIPLET_H_
#define CODE_CPP_EULER_PYTHAGOREANTRIPLET_H_

#include <cstdint>

class PythagoreanTriplet {

  private:  // NOLINT(whitespace/indent)
    uint64_t a, b, c, nsum;

  public:  // NOLINT(whitespace/indent)
    PythagoreanTriplet();
    explicit PythagoreanTriplet(uint64_t a, uint64_t b, uint64_t c);
    ~PythagoreanTriplet() {}
    PythagoreanTriplet& operator=(const PythagoreanTriplet&) = delete;
    PythagoreanTriplet(const PythagoreanTriplet&) = delete;

    uint64_t sum() const;
    bool isPythagorean() const;
    void setABC(uint64_t a, uint64_t b, uint64_t c);
};

#endif  // CODE_CPP_EULER_PYTHAGOREANTRIPLET_H_
