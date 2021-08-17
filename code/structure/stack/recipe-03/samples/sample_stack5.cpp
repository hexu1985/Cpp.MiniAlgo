// stack::top
#include <iostream>     // std::cout
#include "stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int> mystack;

  mystack.Push(10);
  mystack.Push(20);

  mystack.Top() -= 5;

  std::cout << "mystack.Top() is now " << mystack.Top() << '\n';

  return 0;
}
