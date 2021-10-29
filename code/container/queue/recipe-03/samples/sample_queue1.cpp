#include <assert.h>
#include <iostream>
#include "queue.hpp"

using namespace std;
using namespace mini_algo;

int main()
{
	Queue<int> queue1;

	// 测试enqueue
	for (int i = 0; i < 5; ++i)
		queue1.Push(i);

	cout << "queue1.Size(): " << queue1.Size() << endl;
	cout << "queue1.Front(): " << queue1.Front() << endl;
	cout << "queue1.Back(): " << queue1.Back() << endl;

	// 测试dequeue
	while (!queue1.IsEmpty()) {
		cout << ' ' << queue1.Pop();
	}
	cout << endl;

    int n = 0;
    while (n < 100) {
        queue1.Push(++n);
    }

    int sum = 0;
    while (!queue1.IsEmpty()) {
        sum += queue1.Pop();
    }
    cout << "sum: " << sum << endl;

	cout << "queue1.Size(): " << queue1.Size() << endl;

	return 0;
}

