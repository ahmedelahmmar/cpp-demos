#include <bits/stdc++.h>

#include "experiments/multi-threading/hello_world.hpp"
#include "experiments/multi-threading/resource_sync.hpp"
#include "experiments/multi-threading/thread_comm.hpp"

int main(const int argc, const char **argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);

    multi_threading::run_thread_comm();

    return 0;
}