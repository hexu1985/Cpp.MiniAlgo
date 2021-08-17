#include <assert.h>
#include <iostream>
#include <gtest/gtest.h>

#include "stack.hpp"

using namespace std;
using namespace mini_algo;

TEST(StackTest, Methods) {
	Stack<int> stack1;

	EXPECT_TRUE(stack1.IsEmpty());
	EXPECT_EQ(0, stack1.Size());

	// 测试push
	for (int i = 0; i < 5; ++i)
		stack1.Push(i);

	cout << "stack1.Size(): " << stack1.Size() << endl;
	cout << "stack1.Top(): " << stack1.Top() << endl;

	EXPECT_FALSE(stack1.IsEmpty());
	EXPECT_EQ(5, stack1.Size());
	EXPECT_EQ(4, stack1.Top());

	// 测试pop
	while (!stack1.IsEmpty()) {
		cout << ' ' << stack1.Pop();
	}
	cout << endl;

    int n = 0;
    while (n < 100) {
        stack1.Push(++n);
    }

    int sum = 0;
    while (!stack1.IsEmpty()) {
        sum += stack1.Pop();
    }
    cout << "sum: " << sum << endl;

	cout << "stack1.Size(): " << stack1.Size() << endl;
}
