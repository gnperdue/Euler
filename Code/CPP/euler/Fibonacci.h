#ifndef Fibonacci_h
#define Fibonacci_h

#include <vector>

class Fibonacci {

  private:
    std::vector<unsigned long int> fiboNums;

  public:
    Fibonacci(unsigned long int initialLength);
    ~Fibonacci() {}

    Fibonacci& operator=(const Fibonacci&) = delete;
    Fibonacci(const Fibonacci&);

    unsigned long int operator[](unsigned int i) const;
    unsigned int size() const;
    void addFiboNumber();

};

#endif

