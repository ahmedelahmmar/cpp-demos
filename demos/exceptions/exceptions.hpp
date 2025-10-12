#pragma once

#include <stdexcept>
#include <iostream>

namespace demos::exceptions
{
/**
 * Throws an exception whenever you invoke it with an argument equal to 0xACE
 */
struct PodThrowingException
{
    void invoke(int);
};

void run_demo(void);
} // namespace exceptions
