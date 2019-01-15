#include<iostream>
#include<stack>

//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) --将元素 x 推入栈中。
//pop() --删除栈顶的元素。
//top() --获取栈顶元素。
//getMin() --检索栈中的最小元素。


//思路：定义2个栈，栈A存储数据，栈B随时更新栈A的最小数据
using namespace std;
class MinStack {
public:
	
	MinStack() {

	}

	void push(int x) {
		_stack.push(x);
		if (_minstack.empty() || x <= _minstack.top())//更新栈A的最小数据并存到栈B中
		{
			_minstack.push(x);
		}
	}

	void pop() {
		if (_minstack.top() == _stack.top())
			_minstack.pop();

		_stack.pop();
	}

	int top() {
		return _stack.top();
	}

	int getMin() {
		return _minstack.top();

	}
private:
	stack<int> _stack;//数据栈
	stack<int> _minstack;//最小栈
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/



