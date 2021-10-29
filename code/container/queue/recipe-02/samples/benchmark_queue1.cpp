/** \example queue/benchmark_queue1.cpp
 * This is an example of how to use the std::queue class.
 */
#include <assert.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int max_queue_size = 100;
	queue<int> queue1;

	assert(queue1.empty());
	assert(queue1.size() == 0);

	// 测试enqueue
	for (int i = 0; i < 5; ++i)
		queue1.push(i);

	cout << "queue1.size(): " << queue1.size() << endl;
	cout << "queue1.front(): " << queue1.front() << endl;
	cout << "queue1.back(): " << queue1.back() << endl;

	assert(!queue1.empty());
	assert(queue1.size() == 5);
	assert(queue1.front() == 0);
	assert(queue1.back() == 4);

	// 测试dequeue
	while (!queue1.empty()) {
		cout << ' ' << queue1.front();
        queue1.pop();
	}
	cout << endl;

    int n = 0;
    while (queue1.size() < max_queue_size) {
        queue1.push(++n);
    }

    int sum = 0;
    while (!queue1.empty()) {
        sum += queue1.front();
        queue1.pop();
    }
    cout << "sum: " << sum << endl;

	cout << "queue1.size(): " << queue1.size() << endl;

	return 0;
}

