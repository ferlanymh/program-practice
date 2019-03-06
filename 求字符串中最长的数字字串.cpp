#include<iostream>
#include<string>

using namespace std;

//遍历数组，遇到0-9之间的字符就让end继续向前走，直到end到达末尾或者非法值，然后比较这个字串长度是否大于ret，大于则更新，不大于不改变
int main()
{
	string s;
	cin >> s;

	string ret;
	int begin = 0;
	int end = 0;
	while (begin < s.size())
	{
		if (s[begin] >= '0' && s[begin] <= '9')//此时是合法值
		{
			end = begin;
			while (end < s.size() && s[end] >= '0' && s[end] <= '9')//继续让end向前走，直到末尾或者非法值
			{
				end++;
			}
			if (end - begin > ret.size())//比较这个字串与之前的结果长度，取长的作为新ret
			{
				ret.clear();
				ret = s.substr(begin, end-begin);
			}
			if (end == s.size())//如果end到达末尾，没必要再比，退出即可。
				break;
		}
		begin++;
	}
	cout << ret << endl;

	return 0;
}
