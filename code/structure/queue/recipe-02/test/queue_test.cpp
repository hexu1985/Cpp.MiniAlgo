#include <assert.h>
#include <iostream>
#include <gtest/gtest.h>

#include "queue.hpp"

using namespace std;
using namespace mini_algo;

TEST(QueueTest, Methods) {
	Queue<int> queue1(100);

	EXPECT_TRUE(queue1.IsEmpty());
	EXPECT_FALSE(queue1.IsFull());
	EXPECT_EQ(0, queue1.Size());
	EXPECT_EQ(100, queue1.Capacity());

	// 测试enqueue
	for (int i = 0; i < 5; ++i)
		queue1.Push(i);

	cout << "queue1.Size(): " << queue1.Size() << endl;
	cout << "queue1.Capacity(): " << queue1.Capacity() << endl;
	cout << "queue1.Front(): " << queue1.Front() << endl;
	cout << "queue1.Back(): " << queue1.Back() << endl;

	EXPECT_FALSE(queue1.IsEmpty());
	EXPECT_FALSE(queue1.IsFull());
	EXPECT_EQ(5, queue1.Size());
	EXPECT_EQ(0, queue1.Front());
	EXPECT_EQ(4, queue1.Back());

	// 测试dequeue
	while (!queue1.IsEmpty()) {
		cout << ' ' << queue1.Pop();
	}
	cout << endl;

    int n = 0;
    while (!queue1.IsFull()) {
        queue1.Push(++n);
    }

    int sum = 0;
    while (!queue1.IsEmpty()) {
        sum += queue1.Pop();
    }
    cout << "sum: " << sum << endl;

	cout << "queue1.Size(): " << queue1.Size() << endl;
	cout << "queue1.Capacity(): " << queue1.Capacity() << endl;
}

