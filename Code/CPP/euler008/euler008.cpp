#include <iostream>     // NOLINT(readability/streams)
#include <fstream>      // NOLINT(readability/streams)
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char * argv[]) {

  std::string file_name = "numbers.txt";
  // numbers.txt is like:
  // 12345
  // 67890
  // etc.
  std::ifstream file(file_name);

  std::vector<uint64_t> numbers;

  std::string line;
  // get each line...
  while (std::getline(file, line)) {
    // loop over the characters in the line (string)...
    for (char c : line) {
      // cast each char as an int, subtract 48 to get proper value
      numbers.push_back(static_cast<uint64_t>(c) - 48);
    }
  }

  uint64_t max_product = 0;
  int num_numbers = numbers.size();
  int num_vals_in_chunk = 13;
  for (int i = 0; i < num_numbers - num_vals_in_chunk; ++i) {
    uint64_t product = 1;
    for (int j = i; j < i + num_vals_in_chunk; ++j) {
      product *= numbers[j];
    }
    if (product > max_product) {
      max_product = product;
    }
  }
  std::cout << max_product << std::endl;

  return 0;
}
