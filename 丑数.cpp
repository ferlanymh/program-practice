



class Solution {
public:
    int GetMin(int num2,int num3,int num5)
    {
        int min = num2 < num3 ? num2 : num3;
        min = min < num5 ? min : num5;
        return min;
    }
    int GetUglyNumber_Solution(int index) {
        int* UglyNums = new int[index];//存放排序的丑数
        UglyNums[0] = 1;//第一个丑数是1.
        
        int* ugly2 = UglyNums;
        int* ugly3 = UglyNums;
        int* ugly5 = UglyNums;
        
        for (int i = 1;i < index;i++)
        {
            int min = GetMin(*ugly2 * 2,*ugly3 * 3,*ugly5 * 5);//取到下一个最小的丑数
            UglyNums[i] = min;
            
            if (*ugly2 * 2 <= min)//我们要保证下次求的最小丑数肯定大于min，不然求就没有意义
                ++ugly2;
            if (*ugly3 * 3 <= min)
                ++ugly3;
            if (*ugly5 * 5 <= min)
                ++ugly5;
            
        }
        
        int ret = UglyNums[index - 1];//结果
        delete[] UglyNums;
        return ret;
    }
};
