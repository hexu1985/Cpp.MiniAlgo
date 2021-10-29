#include <assert.h>
#include <iostream>
#include "stack.hpp"

using namespace mini_algo;
using namespace std;

int main()
{
	Stack<int> stack1(100);

	// 测试push
	for (int i = 0; i < 5; ++i)
		stack1.Push(i);

	cout << "stack1.Size(): " << stack1.Size() << endl;
	cout << "stack1.Capacity(): " << stack1.Capacity() << endl;
	cout << "stack1.Top(): " << stack1.Top() << endl;

	// 测试pop
	while (!stack1.IsEmpty()) {
		cout << ' ' << stack1.Pop();
	}
	cout << endl;

    int n = 0;
    while (!stack1.IsFull()) {
        stack1.Push(++n);
    }

    int sum = 0;
    while (!stack1.IsEmpty()) {
        sum += stack1.Pop();
    }
    cout << "sum: " << sum << endl;

	cout << "stack1.size(): " << stack1.Size() << endl;
	cout << "stack1.capacity(): " << stack1.Capacity() << endl;

	return 0;
}
