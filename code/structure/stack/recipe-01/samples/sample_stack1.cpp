#include <assert.h>
#include <iostream>
#include "Stack.hpp"

using namespace std;
using namespace mini_algo;

int main()
{
	Stack<int, 100> stack1;

	// 测试push
	for (int i = 0; i < 5; ++i)
		stack1.push(i);

	cout << "stack1.size(): " << stack1.size() << endl;
	cout << "stack1.capacity(): " << stack1.capacity() << endl;
	cout << "stack1.top(): " << stack1.top() << endl;

	// 测试pop
	while (!stack1.isEmpty()) {
		cout << ' ' << stack1.pop();
	}
	cout << endl;

    int n = 0;
    while (!stack1.isFull()) {
        stack1.push(++n);
    }

    int sum = 0;
    while (!stack1.isEmpty()) {
        sum += stack1.pop();
    }
    cout << "sum: " << sum << endl;

	cout << "stack1.size(): " << stack1.size() << endl;
	cout << "stack1.capacity(): " << stack1.capacity() << endl;

	return 0;
}
