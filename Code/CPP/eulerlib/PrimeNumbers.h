#ifndef CODE_CPP_EULER_PRIMENUMBERS_H_
#define CODE_CPP_EULER_PRIMENUMBERS_H_

#include <vector>

class PrimeNumbers {

  private:      // NOLINT(whitespace/indent)
    std::vector<uint64_t> primeNumbers;

  public:      // NOLINT(whitespace/indent)
    PrimeNumbers() { primeNumbers.push_back(1L); }
    ~PrimeNumbers() {}

    uint64_t operator[](uint64_t i) const;
    unsigned int size() const;
    void addPrimeNumber();

    bool isPrime(uint64_t num) const;
    uint64_t nextPrime(uint64_t val) const;
};

#endif  // CODE_CPP_EULER_PRIMENUMBERS_H_

