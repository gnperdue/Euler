#ifndef CODE_CPP_EULER_PROPERDIVISORS_H_
#define CODE_CPP_EULER_PROPERDIVISORS_H_

#include <cstdint>
#include <vector>
#include <set>

class ProperDivisors {

  private:  // NOLINT(whitespace/indent)
    uint64_t value;

  public:   // NOLINT(whitespace/indent)
    ProperDivisors();
    explicit ProperDivisors(uint64_t value);
    ~ProperDivisors() {}

    void set(uint64_t value);
    std::vector<uint64_t> divisors() const;
    std::set<uint64_t> divisors_set() const;
    uint64_t sum_of_divisors() const;
};

#endif  // CODE_CPP_EULER_PROPERDIVISORS_H_
