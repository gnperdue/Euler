#include <iostream>  // NOLINT(readability/streams)
#include <fstream>   // NOLINT(readability/streams)
#include <algorithm>
#include <string>
#include <vector>

// remove the first and last character of a string - in this case we know they
// are all "quoted" and we want to remove those chars.
std::string clean_quotes(std::string s) {
  s.erase(s.begin());
  s.erase(s.end() - 1);
  return s;
}

// split a line (string) with tokens separated by `,` characters and return
// a vector of tokens (strings).
std::vector<std::string> split_by_comma(
    const std::string &line, bool debug = false
    ) {
  const char sep = static_cast<char>(44);
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = line.find(sep, start)) != std::string::npos) {
		if (end != start) {
			if (debug) {
				std::cout << "start,end = " << start << "," << end << ": " <<
					clean_quotes(line.substr(start, end - start)) << std::endl;
			}
			tokens.push_back(clean_quotes(line.substr(start, end - start)).c_str());
		}
		start = end + 1;
	}
	if (end != start) {
		if (debug) {
			std::cout << "start,end = " << start << "," << end << ": " <<
				clean_quotes(line.substr(start, end - start)) << std::endl;
		}
		tokens.push_back(clean_quotes(line.substr(start).c_str()));
	}
	return tokens;
}

// score the name
uint64_t score_name(std::string& name, uint64_t index) {
  uint64_t offset = 64;
  uint64_t sum = 0;
  for (auto c : name) {
    sum += uint64_t(c) - offset;
  }
  return sum * index;
}

int main(int argc, char * argv[]) {

	std::string file_name = "p022_names_short.txt";
  bool print_names = false;

	int optind = 1;
	while ((optind < argc) && argv[optind][0] == '-') {
		std::string sw = argv[optind];
		if (sw == "-f" || sw == "--file") {
			optind++;
			file_name = argv[optind];
		}
		if (sw == "-p" || sw == "--print_names") {
			print_names = true;
		}
		optind++;
	}

  std::vector<std::string> names;
	std::string line;

  // open the file
	std::ifstream file(file_name);
  // read the file in line by line
	while (std::getline(file, line)) {
		std::vector<std::string> linevals = split_by_comma(line);
    // extend our vector of tokens (names)
		names.insert(names.end(), linevals.begin(), linevals.end());
	}

  if (print_names) {
    std::cout << "\nNames...\n" << std::endl;
    for (auto s : names) {
      std::cout << s << std::endl;
    }
  }

  // sort the names
  std::sort(names.begin(), names.end());

  if (print_names) {
    std::cout << "\nSorted Names...\n" << std::endl;
    for (auto s : names) {
      std::cout << s << std::endl;
    }
  }

  // test...
  // std::string s("COLIN");
  // std::cout << score_name(s, 938) << std::endl;

  uint64_t idx = 1;
  uint64_t score = 0;
  for (auto s : names) {
    score += score_name(s, idx);
    idx++;
  }
  std::cout << "\nTotal score = " << score << std::endl;


  return 0;
}

