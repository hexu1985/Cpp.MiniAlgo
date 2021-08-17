// stack::top
#include <iostream>     // std::cout
#include "Stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int,100> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}
