/** \example queue/benchmark_queue2.cpp
 * This is an example of how to use the std::queue class.
 */
// queue::empty
#include <iostream>       // std::cout
#include <queue>          // std::queue

using namespace std;

int main ()
{
  queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
