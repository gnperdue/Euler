#ifndef Palindromic_h
#define Palindromic_h

#include <vector>

class Palindromic {

  private:
    int value;
    void init(int theValue);

  public:
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

#endif
