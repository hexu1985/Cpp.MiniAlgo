// Queue::push/pop
#include <iostream>         // std::cin, std::cout
#include "Queue.hpp"   // Queue

using namespace mini_algo;

int main ()
{
  Queue<int> myqueue(10);
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint && !myqueue.isFull());

  std::cout << "myqueue contains: ";
  while (!myqueue.isEmpty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}
