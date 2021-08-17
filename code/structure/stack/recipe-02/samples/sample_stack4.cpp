// stack::size
#include <iostream>     // std::cout
#include "stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int> myints;
  std::cout << "0. size: " << myints.Size() << '\n';

  for (int i=0; i<5; i++) myints.Push(i);
  std::cout << "1. size: " << myints.Size() << '\n';

  myints.Pop();
  std::cout << "2. size: " << myints.Size() << '\n';

  return 0;
}
