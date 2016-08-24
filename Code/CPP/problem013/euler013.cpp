#include <iostream>     // NOLINT(readability/streams)
#include <fstream>      // NOLINT(readability/streams)
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char * argv[]) {

  std::string file_name = "numbers_short13.txt";
  // numbers.txt is like:
  // 12345
  // 67890
  // etc.
  std::ifstream file(file_name);

  std::vector<uint64_t> numbers;

  std::string line;
  // get each line...
  while (std::getline(file, line)) {
		// for each line we have a new vector to build the number
		std::vector<uint64_t> linevals;
    // loop over the characters in the line (string)...
    for (char c : line) {
      // cast each char as an int, subtract 48 to get proper value
      linevals.push_back(static_cast<uint64_t>(c) - 48);
    }
		uint64_t the_num = 0;
    uint64_t mult_factor = 1;
    for (auto i = linevals.rbegin(); i != linevals.rend(); ++i) {
      std::cout << (*i) << std::endl;
      the_num += mult_factor * (*i);
      mult_factor *= 10;
      std::cout << the_num << std::endl;
    }
    numbers.push_back(the_num);
  }

  // form the sum
  uint64_t grand_sum = 0;
  for (auto n : numbers) {
    grand_sum += n;
  }

  std::cout << "grand sum = " << grand_sum << std::endl;
  // get the 10 most significant digits
  std::cout << "first ten = "
    << grand_sum - (grand_sum % 10000000000) << std::endl;

  return 0;
}
