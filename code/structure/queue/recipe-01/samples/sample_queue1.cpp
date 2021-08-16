/** \example array_queue/sample_array_queue1.cpp
 * This is an example of how to use the Queue class.
 */
#include <assert.h>
#include <iostream>
#include "Queue.hpp"

using namespace std;

int main()
{
	Queue<int, 100> queue1;

	// 测试enqueue
	for (int i = 0; i < 5; ++i)
		queue1.push(i);

	cout << "queue1.size(): " << queue1.size() << endl;
	cout << "queue1.capacity(): " << queue1.capacity() << endl;
	cout << "queue1.front(): " << queue1.front() << endl;
	cout << "queue1.back(): " << queue1.back() << endl;

	// 测试dequeue
	while (!queue1.isEmpty()) {
		cout << ' ' << queue1.pop();
	}
	cout << endl;

    int n = 0;
    while (!queue1.isFull()) {
        queue1.push(++n);
    }

    int sum = 0;
    while (!queue1.isEmpty()) {
        sum += queue1.pop();
    }
    cout << "sum: " << sum << endl;

	cout << "queue1.size(): " << queue1.size() << endl;
	cout << "queue1.capacity(): " << queue1.capacity() << endl;

	return 0;
}

