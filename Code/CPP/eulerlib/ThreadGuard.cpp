
#include "ThreadGuard.h"

//-----------------------------------------------
ThreadGuard::ThreadGuard(std::thread& theThr):
      thr(theThr) 
{
}

//-----------------------------------------------
ThreadGuard::~ThreadGuard() 
{
  if (thr.joinable()) thr.join();
}

