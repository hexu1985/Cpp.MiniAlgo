/** \example queue/benchmark_queue4.cpp
 * This is an example of how to use the std::queue class.
 */
// queue::front
#include <iostream>       // std::cout
#include <queue>          // std::queue

using namespace std;

int main ()
{
  queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

  return 0;
}
