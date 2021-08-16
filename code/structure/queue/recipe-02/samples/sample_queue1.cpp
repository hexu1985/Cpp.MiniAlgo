#include <assert.h>
#include <iostream>
#include "Queue.hpp"

using namespace mini_algo;
using namespace std;

int main()
{
	Queue<int> queue1(100);

	assert(queue1.isEmpty());
	assert(!queue1.isFull());
	assert(queue1.size() == 0);
	assert(queue1.capacity() == 100);

	// 测试enqueue
	for (int i = 0; i < 5; ++i)
		queue1.push(i);

	cout << "queue1.size(): " << queue1.size() << endl;
	cout << "queue1.capacity(): " << queue1.capacity() << endl;
	cout << "queue1.front(): " << queue1.front() << endl;
	cout << "queue1.back(): " << queue1.back() << endl;

	assert(!queue1.isEmpty());
	assert(!queue1.isFull());
	assert(queue1.size() == 5);
	assert(queue1.front() == 0);
	assert(queue1.back() == 4);

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

