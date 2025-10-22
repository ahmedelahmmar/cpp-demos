#pragma once

#include <iostream>
#include <mutex>
#include <thread>

int gCounter1 = 0;
int gCounter2 = 0;
std::mutex mtx;

namespace multi_threading
{
  void run_resource_sync(void)
  {
    auto increment_with_mtx = [](int id)
    {
      for (int i = 0; i < 10'000; i++)
      {
        // we can use std::lock_guard<std::mutex> to create a raii lock
        mtx.lock();
        ++gCounter1;
        std::cout << "Thread " << id << " incremented protected counter to " << gCounter1 << std::endl;
        mtx.unlock();
      }
    };

    auto increment_without_mtx = [](int id)
    {
      for (int i = 0; i < 10'000; i++)
      {
        ++gCounter2;
        std::cout << "Thread " << id << " incremented unprotected counter to " << gCounter2 << std::endl;
      }
    };
    
    std::thread t1(increment_with_mtx, 1);
    std::thread t2(increment_with_mtx, 2);
    std::thread t3(increment_without_mtx, 3);
    std::thread t4(increment_without_mtx, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\nprotected counter = " << gCounter1 << std::endl;
    std::cout << "unprotected counter = " << gCounter2 << std::endl;
  }
}