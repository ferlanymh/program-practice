
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