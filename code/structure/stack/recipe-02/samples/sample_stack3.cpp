// stack::push/pop
#include <iostream>     // std::cout
#include "stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.Push(i);

  std::cout << "Popping out elements...";
  while (!mystack.IsEmpty())
  {
     std::cout << ' ' << mystack.Top();
     mystack.Pop();
  }
  std::cout << '\n';

  return 0;
}
