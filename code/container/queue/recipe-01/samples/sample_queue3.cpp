// Queue::push/pop
#include <iostream>         // std::cin, std::cout
#include "queue.hpp"   // Queue

using namespace mini_algo;

int main ()
{
  Queue<int, 10> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myqueue.Push (myint);
  } while (myint && !myqueue.IsFull());

  std::cout << "myqueue contains: ";
  while (!myqueue.IsEmpty())
  {
    std::cout << ' ' << myqueue.Front();
    myqueue.Pop();
  }
  std::cout << '\n';

  return 0;
}
