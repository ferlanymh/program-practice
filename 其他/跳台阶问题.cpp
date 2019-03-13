/*题目描述一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。



思路：  其实和斐波那契数列很像
跳1级台阶，有1种跳法，
跳2级台阶，有2种跳法，
跳3级台阶，有3种跳法，
跳4级台阶，有5种跳法，

则跳n级台阶，跳法为跳前两级台阶的跳法之和。
*/


class Solution1 {
public:
	int jumpFloor(int number) {
		if (number == 1)
		{
			return 1;
		}
		else if (number == 2)
		{
			return 2;
		}
		else return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};




class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;


		int ret = 3;
		int prev = 2;
		for (int i = 3;i<number;i++)
		{
			int tmp = ret;
			ret += prev;
			prev = tmp;
		}
		return ret;
	}
};