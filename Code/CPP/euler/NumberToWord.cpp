#include "NumberToWord.h"   // NOLINT(build/include)

NumberToWord::NumberToWord() {
  one_to_nine = {
    {0, ""}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
    {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}
  };
  teens = {
    {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"},
    {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
    {18, "eighteen"}, {19, "nineteen"}
  };
  decades = {
    {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"},
    {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}
  };
}

std::string NumberToWord::number_to_word(uint64_t number) const { 
  if (number > 0 && number < 10) {
    return one_to_nine.at(number);
  } else if (number >= 10 && number < 20) {
    return teens.at(number);
  } else if (number >= 20 && number < 100) {
    uint64_t rem = number % 10;
    number = number - rem;
    return decades.at(number) + one_to_nine.at(rem);
  } else if (number >= 100 && number < 1000) {
    uint64_t simple = number % 100;
    uint64_t century = (number - simple) / 100;
    std::string ender;
    if (simple == 0) {
      ender = "";
    } else {
      ender = "and" + number_to_word(simple);
    }
    return one_to_nine.at(century) + "hundred" + ender;
  } else if (number == 1000) {
    return "onethousand";
  }
  return "BAD NUMBER!";
}
