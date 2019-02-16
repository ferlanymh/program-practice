求一个数字k在一个排序数组中出现的个数.


思路1:   
从头开始遍历 , 从遇到k开始进行计数,一直记到不是k为止或者到达数组末尾.
如果数组为空或者直到数组末尾都始终没有找到k则返回0;


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())
            return 0;
        int num = 0;
        vector<int>::iterator it = data.begin();
        while (*it != k && it != data.end())
        {
            it++;
        }
        if (it == data.end())
            return 0;
        else
        {
            while (*it==k && it != data.end())
            {
                num++;
                it++;
            }
                
        }
        return num;
    }
};
