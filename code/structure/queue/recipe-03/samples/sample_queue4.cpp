// Queue::front
#include <iostream>         // std::cout
#include "queue.hpp"   // Queue

using namespace mini_algo;

int main ()
{
  Queue<int> myqueue;

  myqueue.Push(77);
  myqueue.Push(16);

  myqueue.Front() -= myqueue.Back();    // 77-16=61

  std::cout << "myqueue.Front() is now " << myqueue.Front() << '\n';

  return 0;
}
