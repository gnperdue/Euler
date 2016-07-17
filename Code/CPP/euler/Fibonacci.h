#ifndef Fibonacci_h
#define Fibonacci_h

#include <vector>

class Fibonacci {

  private:
    std::vector<unsigned long int> fiboNums;

  public:
    explicit Fibonacci(uint64_t initialLength);
    ~Fibonacci() {}

    Fibonacci& operator=(const Fibonacci&) = delete;
    Fibonacci(const Fibonacci&);

    uint64_t operator[](uint64_t i) const;
    unsigned int size() const;
    void addFiboNumber();
};

#endif

