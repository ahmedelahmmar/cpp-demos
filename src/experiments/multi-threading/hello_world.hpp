#pragma once

#include <iostream>
#include <chrono>
#include <thread>

namespace multi_threading
{
  void run_hello_world(void)
  {
    auto print_with_id = [](int id)
    {
      std::cout << "Started printing thread #" << id << '\n';
      for (int i = 0; i < 5; i++)
      {
        std::cout << "Hello, multi-threading world! from thread #" << id << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
      std::cout << "Exiting printing thread #" << id << '\n';
    };
    
    std::cout << "Started main thread!\n";
    std::thread t1(print_with_id, 1);

    for (int i = 0; i < 3; i++)
    {
      std::cout << "Hello, multi-threading world! from main thread\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    if (t1.joinable())
    {
      std::cout << "Main thread waiting for printing thread\n";
      t1.join();
    }

    std::cout << "Exiting main thread\n";
  }
}