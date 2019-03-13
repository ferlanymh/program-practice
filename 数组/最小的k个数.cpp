//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。




//当个数不多的时候，可以采用排序再输出的方式来完成。

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;

        if (input.empty() || input.size() < k)
            return result;
        sort(input.begin(),input.end());
        
        int i = 0;
        while (i < k)
        {
            result.push_back(input[i]);
            i++;
        }
        return result;
        
        
    }
};


/*面对海量数据，最好不要排序。
我们采用set，因为set底层是红黑树，查找方便。
set只存k个数，如果set中数字个数小于k，则直接插入set。
如果等于k，那么取set中最大值与新插入数据进行比较，小的留下，大的删除。

查找set中最大的值采用greater<int>来实现

*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
        if (input.empty() || input.size() < k)
            return vector<int>();
        
        set<int,greater<int>> s;//用set存最小k个数
        vector<int>::iterator vit = input.begin();
       for (;vit != input.end();vit++)
       {
           if (s.size() < (size_t)k)//set中个数少于k
            {
                s.insert(*vit);
            }
            else
            {
                 set<int,greater<int>>::iterator sit = s.begin();
                 if(*(s.begin()) > (*vit))
                 {
                     s.erase(sit);
                     s.insert(*vit);
                 }
            }
           
        
       }
            
        return vector<int>(s.begin(),s.end());

    }
};

