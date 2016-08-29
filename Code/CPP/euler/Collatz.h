#ifndef CODE_CPP_EULER_COLLATZ_H_
#define CODE_CPP_EULER_COLLATZ_H_

#include <string>
#include <vector>

class Collatz {

  private:  // NOLINT(whitespace/indent)
    std::vector<uint64_t> collatzNums;
    void buildSequence();
    uint64_t initialValue;

  public:  // NOLINT(whitespace/indent)
    Collatz();
    explicit Collatz(uint64_t initialValue);
    ~Collatz() {}
    Collatz& operator=(const Collatz&) = delete;
    Collatz(const Collatz&) = delete;

    uint64_t operator[](unsigned int i) const;
    unsigned int size() const;
    const std::vector<uint64_t> *fullSequence() const;
    void reset(uint64_t value);
    std::string toString() const;
};

#endif  // CODE_CPP_EULER_COLLATZ_H_
