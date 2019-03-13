
/*思路：
	查找数组中超过一半的数字，很明显我们需要统计每个数字及他出现的次数，用map就能解决。
	
	遍历一遍数组，将遍历的每个值都作为map中pair的first成员，并用second记录出现次数。
	因为map的operator[ ]底层有插入功能，所以直接对m[numbers[i] ]++即可。
	
	在遍历一遍map，看那个的second的值大于数组size的一半，就返回。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int> m;
        int i = 0;
        
        for (;i<numbers.size();i++)
        {
            m[numbers[i]]++;
        }
        
        map<int,int>::iterator it = m.begin();
        while (it != m.end())
        {
            if ((it->second)*2 > numbers.size())
            {
                return it->first;
            }
            it++;
        }
        return 0;
    }
};

/*
思路2：上面的方法要开辟空间，并且要遍历两遍数组，不够好
如果定义一个tmp记录数变量count记录相同的次数，遇到一个变量就与之前的变量做比较
相同则count++,不同则count--（相当于不同的数抵消了）。倘若count减到0，就重置tmp为当前位置的元素。
可想而知，遍历到最后，tmp的值一定是出现次数最多的数。因为其他的数都怼不过他~
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int tmp = 0;
	vector<int> v;//输入n个数，这里不确定n的值，使用while(cin>>tmp)来持续插入
	while (cin >> tmp)
	{
		v.push_back(tmp);
	}
	if (v.size() == 1)
	{
		cout << v[0] << endl;
		return 0;
	}
	int ret = v[0];//最终结果
	int count = 1;//出现次数

	for (size_t i = 1;i < v.size();i++)
	{
		if (ret == v[i])//相同count++
			count++;
		else
		{
			count--;//不同count--;
			if (count == 0)//当count==0更新ret的位置
			{
				ret = v[i];
				count++;
			}
		}
	}
	cout << ret << endl;//最终ret一定是我们要的值
	
	system("pause");
	return 0;
}
