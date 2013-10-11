#ifndef TriangularNumber_h
#define TriangularNumber_h

#include <vector>

class TriangularNumber {

  private:
    unsigned long initialValue;
    unsigned long triangularNumber;
    void calcTriangle();

  public:
    TriangularNumber();
    TriangularNumber(unsigned long initialValue);
    ~TriangularNumber() {}
    TriangularNumber& operator=(const TriangularNumber&) = delete;
    TriangularNumber(const TriangularNumber&) = delete;

    void set(unsigned long index);
    unsigned long get() const;
    std::vector<unsigned long> factors() const;
};

#endif
