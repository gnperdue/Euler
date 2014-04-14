#include <iostream>
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"

int sum_of_squares(int max) {
  int sum {0};
  tbb::parallel_for(
			static_cast<int>(1), max+1,
      [&](int i){
      sum += i*i;
      }
      );
  return sum;
}

int square_of_sum(int max) {
  int sum {0};
  tbb::parallel_for(
			static_cast<int>(1), max+1,
      [&](int j){
      sum += j;
      }
      );
  return sum * sum;
}

int main(int argc, char * argv[]) {

  int max = 100;
	int sq_of_sum = square_of_sum(max);
	int sum_of_sq = sum_of_squares(max);
	int euler = sq_of_sum - sum_of_sq;
  std::cout << "The answer is " << euler << std::endl;

  return 0;
}

