/** \example array_queue/sample_array_queue4.cpp
 * This is an example of how to use the Queue class.
 */
// Queue::front
#include <iostream>         // std::cout
#include "Queue.hpp"   // Queue

int main ()
{
  Queue<int, 100> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

  return 0;
}
