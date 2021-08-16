/** \example queue/benchmark_queue3.cpp
 * This is an example of how to use the std::queue class.
 */
// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

using namespace std;

int main ()
{
  queue<int> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}
