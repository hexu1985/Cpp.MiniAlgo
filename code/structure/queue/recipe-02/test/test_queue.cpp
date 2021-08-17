#include <assert.h>
#include <iostream>
#include <gtest/gtest.h>

#include "Queue.hpp"

using namespace std;
using namespace mini_algo;

TEST(QueueTest, Methods) {
	Queue<int> queue1(100);

	EXPECT_TRUE(queue1.isEmpty());
	EXPECT_FALSE(queue1.isFull());
	EXPECT_EQ(0, queue1.size());
	EXPECT_EQ(100, queue1.capacity());

	// 测试enqueue
	for (int i = 0; i < 5; ++i)
		queue1.push(i);

	cout << "queue1.size(): " << queue1.size() << endl;
	cout << "queue1.capacity(): " << queue1.capacity() << endl;
	cout << "queue1.front(): " << queue1.front() << endl;
	cout << "queue1.back(): " << queue1.back() << endl;

	EXPECT_FALSE(queue1.isEmpty());
	EXPECT_FALSE(queue1.isFull());
	EXPECT_EQ(5, queue1.size());
	EXPECT_EQ(0, queue1.front());
	EXPECT_EQ(4, queue1.back());

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
}

