#include <iostream>  // NOLINT(readability/streams)
#include "NumberToWord.h" // NOLINT(build/include)

int main(int argc, char * argv[]) {

  NumberToWord ntw;
  bool test = false;
  if (test) {
    std::cout << "Testing..." << std::endl;
    std::cout << ntw.number_to_word(342) << std::endl;
    std::cout << ntw.number_to_word(342).length() << std::endl;
  }

  std::string euler = "";
  for (uint64_t i = 1; i < 1001; ++i) {
    euler += ntw.number_to_word(i);
  }
  std::cout << euler.length() << std::endl;

  return 0;
}

