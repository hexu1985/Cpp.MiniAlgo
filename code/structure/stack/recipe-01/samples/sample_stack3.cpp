// stack::push/pop
#include <iostream>     // std::cout
#include "Stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int,100> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.isEmpty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  return 0;
}
