#ifndef Collatz_h
#define Collatz_h

#include <string>
#include <vector>

class Collatz {

  private:
    std::vector<unsigned long> collatzNums;
    void buildSequence();
    unsigned long initialValue;

  public:
    Collatz();
    Collatz(unsigned long initialValue);
    ~Collatz() {}
    Collatz& operator=(const Collatz&) = delete;
    Collatz(const Collatz&) = delete;

    unsigned long operator[](unsigned int i) const;
    unsigned int size() const;
    const std::vector<unsigned long> *fullSequence() const;
    void reset(unsigned long value);
    std::string toString() const;
};

#endif
