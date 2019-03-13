
//题目描述//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。


//思路： 跟跳台阶问题类似，先列出来前几项，得出规律先

//1级      1种
//2级      2种
//3级      4种
//4级      8种


//n级       2^(n-1)种




class Solution {
public:
	int jumpFloorII(int number) {
		int i;
		int ret = 1;
		for (i = 1;i<number;i++)
		{
			ret *= 2;
		}
		return ret;
	}
};