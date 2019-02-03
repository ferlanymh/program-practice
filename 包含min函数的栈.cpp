class Solution {
public:
    void push(int value) {
        s.push(value);
        if (s_min.empty() || s_min.top() >= value)
            s_min.push(value);
    }
    void pop() {
        int ret = s.top();
        s.pop();
        if (ret == s_min.top())
            s_min.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return s_min.top();
    }
private:
    stack<int> s;
    stack<int> s_min;
};