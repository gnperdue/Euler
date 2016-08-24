#include <iostream>     // NOLINT(readability/streams)
#include <fstream>      // NOLINT(readability/streams)
#include <string>
#include <vector>

int main(int argc, char * argv[]) {

  std::string file_name = "numbers13.txt";
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
    // get the first 11 numbers to build the sum? - same as 12, 13
    int idx = 11;
    while (idx >= 0) {
      the_num += mult_factor * linevals[idx];
      idx--;
      mult_factor *= 10;
    }
    numbers.push_back(the_num);
  }

  // form the sum
  uint64_t grand_sum = 0;
  for (auto n : numbers) {
    grand_sum += n;
  }

  std::cout << "grand sum = " << grand_sum << std::endl;
  std::string numstr = std::to_string(grand_sum);
  int idx = 0;
  for (auto c : numstr) {
    std::cout << c;
    if (++idx > 9) break;
  }
  std::cout << std::endl;

  return 0;
}
