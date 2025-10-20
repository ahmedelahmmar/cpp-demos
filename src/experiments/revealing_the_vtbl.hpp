#pragma once

#include <iostream>

class RevealingTheVtbl
{
  private:
    class Base
    {
      private:
        virtual void foo(void) noexcept
        {
          std::cout << "vtbl revealed!\n";
        }

      public:
        int value;
    };

  public:
    void run(void)
    {
      Base b_obj;

      const void ***ptr = reinterpret_cast<const void ***>(&b_obj);
      std::cout << "(stack) address of b_obj: " << ptr << "\n";
      std::cout << "(.rodata) address of Base's vtbl: " << *ptr << "\n";
      std::cout << "(.rodata) address of first entry in Base's vtbl: " << **ptr << "\n";

      using function_ptr = void(*)(Base *);
      function_ptr fn_foo = reinterpret_cast<function_ptr>(**ptr);
      fn_foo(reinterpret_cast<Base *>(ptr));
    }
};