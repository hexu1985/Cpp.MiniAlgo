/** \example array_queue/sample_array_queue3.cpp
 * This is an example of how to use the Queue class.
 */
// Queue::push/pop
#include <iostream>         // std::cin, std::cout
#include "Queue.hpp"   // Queue

int main ()
{
  Queue<int, 10> myqueue;
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
