// stack::size
#include <iostream>     // std::cout
#include "Stack.hpp"    // stack

using namespace mini_algo;

int main ()
{
  Stack<int,100> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

  return 0;
}
