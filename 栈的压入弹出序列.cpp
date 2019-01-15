#include<iostream>
#include<vector>
#include<stack>

//思路：
//我们发现出栈序列的每个值（比如a），都要先检查包括a在内且a之前的值是否
//
//都已经在栈中，没有则统统先入栈，然后在出栈a，且我们要出栈的值最后一定
//
//在栈顶。那么就好判断了，只要确保我们的值在栈中，直接判断栈顶是否和a值
//
//相同，不同就说明出栈序列错误。直到出栈序列走完，栈也为空时，说明出栈序
//
//列是正确的。
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() && popV.empty())
			return true;
		stack<int> s;
		vector<int>::iterator p1 = pushV.begin();
		vector<int>::iterator p2 = popV.begin();


		while (p2 != popV.end() || !s.empty())
		{
			vector<int>::iterator it = find(pushV.begin(), pushV.end(), *p2);
			if (p1 > it)
			{
				if (s.top() != *p2)
				{
					return false;
				}

			}
			else
			{

				while (p1 <= it)
				{

					s.push(*p1);
					p1++;

				}

			}
			s.pop();
			p2++;
		}
		return true;

	}

};


int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 4,5,3,2,1 };
	vector<int> v1(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> v2(b, b + sizeof(b) / sizeof(b[0]));
	Solution s;
	s.IsPopOrder(v1, v2);
	system("pause");
	return 0;
}