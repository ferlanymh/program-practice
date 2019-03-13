#include<iostream>
#include<vector>
#include<stack>

//˼·��
//���Ƿ��ֳ�ջ���е�ÿ��ֵ������a������Ҫ�ȼ�����a������a֮ǰ��ֵ�Ƿ�
//
//���Ѿ���ջ�У�û����ͳͳ����ջ��Ȼ���ڳ�ջa��������Ҫ��ջ��ֵ���һ��
//
//��ջ������ô�ͺ��ж��ˣ�ֻҪȷ�����ǵ�ֵ��ջ�У�ֱ���ж�ջ���Ƿ��aֵ
//
//��ͬ����ͬ��˵����ջ���д���ֱ����ջ�������꣬ջҲΪ��ʱ��˵����ջ��
//
//������ȷ�ġ�
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