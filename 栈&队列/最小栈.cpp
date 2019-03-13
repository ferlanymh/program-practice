#include<iostream>
#include<stack>

//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//
//push(x) --��Ԫ�� x ����ջ�С�
//pop() --ɾ��ջ����Ԫ�ء�
//top() --��ȡջ��Ԫ�ء�
//getMin() --����ջ�е���СԪ�ء�


//˼·������2��ջ��ջA�洢���ݣ�ջB��ʱ����ջA����С����
using namespace std;
class MinStack {
public:
	
	MinStack() {

	}

	void push(int x) {
		_stack.push(x);
		if (_minstack.empty() || x <= _minstack.top())//����ջA����С���ݲ��浽ջB��
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
	stack<int> _stack;//����ջ
	stack<int> _minstack;//��Сջ
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/



