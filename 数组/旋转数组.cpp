//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。



//思路：题目是将数组开始的元素搬到末尾，如果我们直接将元素再插入到头部肯定是不行的，因为vector头插效率低。
//所以先将数组逆置。然后将数组头部的元素依次尾插，每次插入前比较第一个元素和最后一个元素的大小，若首元素小于等于就插入，如果大于就返回此时数组的最后一个元素。注意下标的值。

class Solution {
public:
    int minNumberInRotateArray(vector<int> a) {
        if (a.empty())
            return 0;
        
        
        reverse(a.begin(),a.end());//逆置
        int size = a.size();
        int i;
        for ( i = 0;i<size;i++)//依次尾插，
        {
            int ret = a[i];
            if (a[i]<=a[size+i-1])//小于等于就插入
            {
                a.push_back(a[i]);
            }
            else
                break;
        }
        return a[size+i-1];//返回最后一个元素。
    }
   
};