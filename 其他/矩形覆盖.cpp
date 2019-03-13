//题目描述我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//
//。。。跟跳台阶一样，也是考察斐波那契数列，代码基本一样。


class Solution 
{ 
public:
	int rectCover(int number)
	{ 
		if (number == 0)    
			return 0;      
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