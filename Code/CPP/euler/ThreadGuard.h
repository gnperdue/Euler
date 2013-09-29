#ifndef ThreadGuard_h
#define ThreadGuard_h

#include <thread>

class ThreadGuard {

  private:
    std::thread& thr;

  public:
    explicit ThreadGuard(std::thread& theThr);
    ~ThreadGuard();
    
    ThreadGuard(ThreadGuard const&) = delete;
    ThreadGuard& operator=(ThreadGuard const&) = delete;
};

#endif
