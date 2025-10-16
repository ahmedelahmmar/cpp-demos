#pragma once

#include <stdexcept>
#include <iostream>

namespace Demos::Exceptions
{
/**
 * Throws an exception whenever you invoke it with an argument equal to 0xACE
 */
struct PodThrowingException
{
    void invoke(int);
};

void Run(void);
} // namespace Exceptions
