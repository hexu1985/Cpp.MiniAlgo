// stack::empty
#include <iostream>     // std::cout
#include "stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int,100> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.Push(i);

  while (!mystack.IsEmpty())
  {
     sum += mystack.Top();
     mystack.Pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}

