#include "exceptions.hpp"

void Demos::Exceptions::PodThrowingException::invoke(int _value)
{
    if (0xACE == _value)
        throw std::runtime_error{"Glad to receive an exceptional ACE."};

    std::cout << "You invoked me with 0x" << std::hex << _value << '\n';
}


void Demos::Exceptions::Run(void)
{
    Demos::Exceptions::PodThrowingException ethrower;

    try
    {
        ethrower.invoke(0x00C0DE);
        ethrower.invoke(0x00FACE);
        ethrower.invoke(0x000ACE);
        ethrower.invoke(0xC0FFEE);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "exception caught with message: " << e.what() << '\n';
    }
}