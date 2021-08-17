#include <assert.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stack1;

	// 测试push
	for (int i = 0; i < 5; ++i)
		stack1.push(i);

	cout << "stack1.size(): " << stack1.size() << endl;
	cout << "stack1.top(): " << stack1.top() << endl;

	// 测试pop
	while (!stack1.empty()) {
		cout << ' ' << stack1.top();
        stack1.pop();
	}
	cout << endl;

    int n = 0;
    while (n < 100) {
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
