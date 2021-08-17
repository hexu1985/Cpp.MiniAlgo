#include <assert.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int max_stack_size = 100;
	stack<int> stack1;

	assert(stack1.empty());
	assert(stack1.size() == 0);

	// 测试push
	for (int i = 0; i < 5; ++i)
		stack1.push(i);

	cout << "stack1.size(): " << stack1.size() << endl;
	cout << "stack1.top(): " << stack1.top() << endl;

	assert(!stack1.empty());
	assert(stack1.size() == 5);
	assert(stack1.top() == 4);

	// 测试pop
	while (!stack1.empty()) {
		cout << ' ' << stack1.top();
        stack1.pop();
	}
	cout << endl;

    int n = 0;
    while (stack1.size() < max_stack_size) {
        stack1.push(++n);
    }

    int sum = 0;
    while (!stack1.empty()) {
        sum += stack1.top();
        stack1.pop();
    }
    cout << "sum: " << sum << endl;

	cout << "stack1.size(): " << stack1.size() << endl;

	return 0;
}
