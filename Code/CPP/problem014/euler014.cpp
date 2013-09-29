#include <iostream>
#include <iomanip>
#include <list>
#include <thread>
#include <mutex>
#include "Collatz.h"

void fillList( std::list< std::pair<unsigned long, unsigned int> >& collatzLengths, 
    unsigned long lowerBound, unsigned long upperBound);

void addToFullListOfSeqs( 
    std::list< std::pair<unsigned long, unsigned int> >& collatzLengths,
    unsigned long init, unsigned int length );

std::list< std::pair<unsigned long, unsigned int> > collatzLengths;

std::mutex theMutex;

typedef std::pair<unsigned long, unsigned int> colpair;

int main(int argc, char * argv[]) 
{
  using namespace std;

  collatzLengths.clear();
  unsigned long maxValue = 100L;
  if (argc > 1) maxValue = (unsigned long)(atoi(argv[1]) + 1);
  unsigned long nDivisions = 4L;
  if (argc > 2) nDivisions = (unsigned long)atoi(argv[2]);

  unsigned long increment = maxValue / nDivisions;
  unsigned long lowerBound = 1L;
  unsigned long upperBound = lowerBound + increment;

  int nBlocks = (int)nDivisions;  
  cout << "Using " << nBlocks << " threads / computation blocks." << endl;
  vector<thread> threads(nBlocks);
  int threadCounter = 0;

  while (upperBound < maxValue) {
    cout << "Get Collatz seqs for range: [" << lowerBound 
     << "," << upperBound << ")" << endl;
    cout << " Launching thread " << threadCounter << endl;
    threads[threadCounter++] = 
      thread( fillList, ref(collatzLengths), lowerBound, upperBound );
    lowerBound = upperBound;
    upperBound += increment;
  }
  if ( upperBound < maxValue ) {
    cout << "Get Collatz seqs for range: [" << upperBound 
     << "," << maxValue << ")" << endl;
    cout << " Launching thread " << threadCounter << endl;
    threads[threadCounter++] = 
      thread( fillList, ref(collatzLengths), upperBound, maxValue );
  }
  else if ( lowerBound < maxValue ) {
    cout << "Get Collatz seqs for range: [" << lowerBound 
     << "," << maxValue << ")" << endl;
    cout << " Launching thread " << threadCounter << endl;
    threads[threadCounter++] = 
      thread( fillList, ref(collatzLengths), lowerBound, maxValue );
  }

  cout << "Now join " << threadCounter << " threads..." << endl;
  for_each( threads.begin(), threads.end(),
      mem_fn(&thread::join) );

  cout << "Longest Chain in the List:" << endl;
  unsigned int maxLength = 0;
  unsigned long maxLengthIndex = 0;
  for (list< colpair >::iterator p=collatzLengths.begin();
      p!=collatzLengths.end();
      ++p) {
    if ( (*p).second > maxLength ) {
      maxLength = (*p).second;
      maxLengthIndex = (*p).first;
    }
  }
  cout << "(init,length) = " 
    << setw(7) << setfill(' ') << maxLengthIndex << "\t" 
    << setw(7) << setfill(' ') << maxLength << endl;

  return 0;
}

void fillList( std::list< colpair >& collatzLengths, 
    unsigned long lowerBound, unsigned long upperBound)
{
  using namespace std;

  Collatz *collatz = new Collatz();
  for (unsigned long i = lowerBound; i < upperBound; ++i) {
    collatz->reset( i );    
    addToFullListOfSeqs( collatzLengths, i, collatz->size() );
  }
  delete collatz;
}

void addToFullListOfSeqs( 
    std::list< colpair >& collatzLengths,
    unsigned long init, unsigned int length )
{
  using namespace std;

  lock_guard<mutex> guard(theMutex);
  collatzLengths.push_back(colpair(init, length));
}

