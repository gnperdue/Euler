#ifndef CODE_CPP_EULER_NUMBERTOWORD_H_
#define CODE_CPP_EULER_NUMBERTOWORD_H_

#include <map>
#include <cstdint>
#include <string>

class NumberToWord {

  private:  // NOLINT(whitespace/indent)
    std::map<uint64_t, std::string> one_to_nine;
    std::map<uint64_t, std::string> teens;
    std::map<uint64_t, std::string> decades;

  public:   // NOLINT(whitespace/indent)
    NumberToWord();
    ~NumberToWord() {}

    std::string number_to_word(uint64_t number) const;
};

#endif  // CODE_CPP_EULER_NUMBERTOWORD_H_
