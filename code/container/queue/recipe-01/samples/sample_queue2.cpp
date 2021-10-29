// Queue::empty
#include <iostream>         // std::cout
#include "queue.hpp"   // Queue

using namespace mini_algo;

int main ()
{
  Queue<int, 100> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.Push(i);

  while (!myqueue.IsEmpty())
  {
     sum += myqueue.Front();
     myqueue.Pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
