#ifndef PrimeNumbers_h
#define PrimeNumbers_h

#include <vector>

class PrimeNumbers {

  private:
    std::vector<unsigned long> primeNumbers;

  public:
    PrimeNumbers() { primeNumbers.push_back(1L); }
    ~PrimeNumbers() {}

    unsigned long int operator[](unsigned int i) const;
    unsigned int size() const;
    void addPrimeNumber();

    bool isPrime(unsigned long num) const;
    unsigned long nextPrime(unsigned long val) const;

};

#endif

