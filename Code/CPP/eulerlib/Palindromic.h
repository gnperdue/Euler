#ifndef CODE_CPP_EULER_PALINDROMIC_H_
#define CODE_CPP_EULER_PALINDROMIC_H_

#include <vector>

class Palindromic {

  private:    // NOLINT(whitespace/indent)
    int value;

  public:     // NOLINT(whitespace/indent)
    explicit Palindromic();
    explicit Palindromic(int theValue);
    ~Palindromic() {}

    bool isPalindromic() const;
    bool isPalindromic(const std::vector<int>& digits) const;
    std::vector<int> digitize() const;
    std::vector<int> digitize(int value) const;

    int getValue() const;
    void setValue(int theValue);
};

#endif  // CODE_CPP_EULER_PALINDROMIC_H_
