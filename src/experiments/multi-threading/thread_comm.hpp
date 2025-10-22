#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <future>

namespace multi_threading
{
  void run_thread_comm(void)
  {
    auto compute = [](std::promise<int> &prom) -> void
    {
      // simulate processing
      std::this_thread::sleep_for(std::chrono::seconds(2));
      int processed_value = 420;
      prom.set_value(processed_value);
    };

    std::promise<int> promise;
    std::future<int> future{ promise.get_future() };

    std::thread t{compute, std::ref(promise)};

    int result = 0;
    if (future.valid())
    {
      std::cout << "future is valid for the first time\n";
      result = future.get(); // blocking until available
      std::cout << "assigned future.get() to result\n";
    }

    if (not future.valid())
      std::cout << "future is valid only once\n";

    std::cout << "result = " << result << "\n";

    if (t.joinable())
      t.join();
      
  }
}