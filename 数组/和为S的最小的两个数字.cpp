/*题目：输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。*/


//思路：定义两个指针，一个指向数组的头，一个指向数组的尾，判断头尾所指元素和是否是sum，大于则尾向左移，小于则头向右移。
//当发现某位置头尾和是sum以后，直接输出即可，因为头尾越靠近则他们的乘积越大。
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int begin = 0;
		int end = array.size() - 1;
        vector<int> v;
		while (end > begin)
		{
            int add = array[begin] + array[end];
			if (add == sum)
			{
		        v.push_back(array[begin]);
                v.push_back(array[end]);
                break;
			}
            else if (add > sum)
                end--;
            else
                begin++;
		}
		
		return v;
	}
};