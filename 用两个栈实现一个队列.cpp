//栈a和栈b实现一个队列
//思路：创建两个栈s1和s2，当要入数据时，只往s1当中入数据，需要出数据时，先看s2里是否有元素，如果有，则先出s2内的数据，如果s2为空，则先将s1的数据依次导到s2中，再出数据。

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};