#include <iostream>  // NOLINT(readability/streams)
#include <fstream>   // NOLINT(readability/streams)
#include <string>
#include <vector>

std::vector<int> split_nums_by_space(const std::string &line, const char sep) {
	bool debug = false;
	std::vector<int> tokens;
	std::size_t start = 0, end = 0;
	while ((end = line.find(sep, start)) != std::string::npos) {
		if (end != start) {
			if (debug) {
				std::cout << "start,end = " << start << "," << end << ": " <<
					line.substr(start, end - start) << std::endl;
			}
			tokens.push_back(atoi(line.substr(start, end - start).c_str()));
		}
		start = end + 1;
	}
	if (end != start) {
		if (debug) {
			std::cout << "start,end = " << start << "," << end << ": " <<
				line.substr(start, end - start) << std::endl;
		}
		tokens.push_back(atoi(line.substr(start).c_str()));
	}
	return tokens;
}

int main(int argc, char * argv[]) {

	std::string file_name = "triang18small.txt";

	int optind = 1;
	while ((optind < argc) && argv[optind][0] == '-') {
		std::string sw = argv[optind];
		if (sw == "-f" || sw == "--file") {
			optind++;
			file_name = argv[optind];
		}
		optind++;
	}

	std::ifstream file(file_name);
	std::vector<std::vector<int>> data;

	std::string line;
	while (std::getline(file, line)) {
		std::vector<int> linevals = split_nums_by_space(line, static_cast<char>(32));
		data.push_back(linevals);
	}

  // hmmm... think about an algorithm:
  // 1. go to the second to last row.
  // 2. loop over each element and compare the left and right child nodes.
  // 3. replace the value in the row with the sum of the value and the larger
  // child.
  // 4. create a vector for each element and store the index of node that was
  // added. maybe use a map<int, vector<int>> where the key is the index of
  // the parent node.
  // 5. then go up one row and repeat the process.
  // 6. now, the index paths are stored in a new map (we may discard the old
  // one).
  // 7. repeat
  // 8. when the length of the "row above" is 1, we've reached the top.
  // ** actually, we don't even need to keep the path for this problem, but
  // we could keep it using pair of maps as we looped.

	int nrows = data.size();
	for (int i = nrows - 1; i > 0; --i) {
    int size_above = data[i - 1].size();
    // std::cout << i << ", size above = " << size_above << std::endl;
    // std::cout << i << ", " << data[i].size() << std::endl;
    for (int j = 0; j < size_above; ++j) {
      int left_child_sum = data[i - 1][j] + data[i][j];
      int right_child_sum = data[i - 1][j] + data[i][j + 1];
      if (right_child_sum > left_child_sum) {
        data[i - 1][j] = right_child_sum;
      } else {
        data[i - 1][j] = left_child_sum;
      }
    }
  }

  // print the whole triangle for debugging purposes...
  // for (int i = 0; i < nrows; ++i) {
  //   for (int j = 0; j < data[i].size(); ++j) {
  //     std::cout << data[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // just print the answer
  std::cout << data[0][0] << std::endl;

  return 0;
}

