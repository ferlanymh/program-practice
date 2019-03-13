#include<iostream>
#include<vector>

using namespace std;


class BitSet
{
public:
	BitSet(size_t len)//len是要表示数据的最大值
	{
		BitTable.resize((len >> 3) + 1);//一个字节可以表示8个数，用len / 8就可以得知要有多少字节表示。
										//+1是因为有可能除出来有小数，为了防止不够放故+1.
	}
	void InputBitSet(int num)//在位图中标记某一个数
	{
		size_t pos = num / 8;//确定是在哪一个字节
		size_t index = num % 8;//确定是在字节的哪一位

		BitTable[pos] |= ((char)1 << index);

	}

	void removeBitSet(int num)//在位图中删除一个数的标记
	{
		size_t pos = num / 8;
		size_t index = num % 8;
		BitTable[pos] &= ~((char)1 << index);
	}

	bool FindBitSet(int num)//在位图中查找一个数的标记
	{
		size_t pos = num / 8;
		size_t index = num % 8;
		if (BitTable[pos] & ((char)1 << index) == 0)
			return false;
		
		return true;

	}
private:
	vector<char> BitTable;
};
