#include <iostream>  // NOLINT(readability/streams)
#include <iomanip>
#include <list>
#include <thread>
#include <mutex>
#include <utility>
#include "Collatz.h"  // NOLINT(build/include)

void fillList(std::list< std::pair<uint64_t, unsigned int> >& collatzLengths,
    uint64_t lowerBound, uint64_t upperBound);

void addToFullListOfSeqs(
    std::list< std::pair<uint64_t, unsigned int> >& collatzLengths,
    uint64_t init, unsigned int length);

std::list<std::pair<uint64_t, unsigned int>> collatzLengths;

std::mutex theMutex;

typedef std::pair<uint64_t, unsigned int> colpair;

int main(int argc, char * argv[]) {
  using std::cout;
  using std::endl;

  collatzLengths.clear();
  uint64_t maxValue = 100L;
  if (argc > 1) maxValue = (uint64_t)(atoi(argv[1]) + 1);
  uint64_t nDivisions = 4L;
  if (argc > 2) nDivisions = (uint64_t)atoi(argv[2]);

  uint64_t increment = maxValue / nDivisions;
  uint64_t lowerBound = 1L;
  uint64_t upperBound = lowerBound + increment;

  int nBlocks = static_cast<int>(nDivisions);
  cout << "Using " << nBlocks << " threads / computation blocks." << endl;
  std::vector<std::thread> threads(nBlocks);  // NOLINT(build/include_what_you_use)
  int threadCounter = 0;

  while (upperBound < maxValue) {
    cout << "Get Collatz seqs for range: [" << lowerBound
     << "," << upperBound << ")" << endl;
    cout << " Launching thread " << threadCounter << endl;
    threads[threadCounter++] =
      std::thread(fillList, ref(collatzLengths), lowerBound, upperBound);
    lowerBound = upperBound;
    upperBound += increment;
  }
  if (upperBound < maxValue) {
    cout << "Get Collatz seqs for range: [" << upperBound
     << "," << maxValue << ")" << endl;
    cout << " Launching thread " << threadCounter << endl;
    threads[threadCounter++] =
      std::thread(fillList, ref(collatzLengths), upperBound, maxValue);
  } else if (lowerBound < maxValue) {
    cout << "Get Collatz seqs for range: [" << lowerBound
     << "," << maxValue << ")" << endl;
    cout << " Launching thread " << threadCounter << endl;
    threads[threadCounter++] =
      std::thread(fillList, ref(collatzLengths), lowerBound, maxValue);
  }

  cout << "Now join " << threadCounter << " threads..." << endl;
  for_each(threads.begin(), threads.end(),
      mem_fn(&std::thread::join));

  cout << "Longest Chain in the List:" << endl;
  unsigned int maxLength = 0;
  uint64_t maxLengthIndex = 0;
  for (std::list<colpair>::iterator p = collatzLengths.begin();
      p != collatzLengths.end();
      ++p) {
    if ((*p).second > maxLength) {
      maxLength = (*p).second;
      maxLengthIndex = (*p).first;
    }
  }
  cout << "(init,length) = "
    << std::setw(7) << std::setfill(' ') << maxLengthIndex << "\t"
    << std::setw(7) << std::setfill(' ') << maxLength << endl;

  return 0;
}

void fillList(std::list<colpair>& collatzLengths,
    uint64_t lowerBound, uint64_t upperBound) {
  Collatz collatz;
  for (uint64_t i = lowerBound; i < upperBound; ++i) {
    collatz.reset(i);
    addToFullListOfSeqs(collatzLengths, i, collatz.size());
  }
}

void addToFullListOfSeqs(
    std::list<colpair>& collatzLengths,
    uint64_t init, unsigned int length) {
  std::lock_guard<std::mutex> guard(theMutex);
  collatzLengths.push_back(colpair(init, length));
}

