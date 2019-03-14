/*井字棋     判断当前井字棋棋局，玩家是否获得胜利
其中    1代表玩家落子，  -1代表电脑落子     0代表没有子*/

#include<iostream>
#include<vector>

using namespace std;
class Board {
public:
	bool checkRow(vector<vector<int>>& v)
	{
		for (int i = 0;i < 3;i++)
		{
			if ((v[i][0] ==1) && (v[i][1] == 1) && (v[i][2] == 1))
				return true;
		}
		return false;
	}
	bool checkCol(vector<vector<int>>& v)
	{
		for (int i = 0;i < 3;i++)
		{
			if ((v[0][i] == 1) && (v[1][i] == 1) && (v[2][i] == 1))
				return true;
		}
		return false;
	}
	bool checkCross(vector<vector<int>>& v)
	{
		if ( ((v[0][0] == 1) && (v[1][1] == 1) && (v[2][2] == 1) ) ||
			((v[0][2] == 1) && (v[1][1] == 1) && (v[2][0] == 1)))
			return true;
		else
			return false;
	}
	bool checkWon(vector<vector<int> > board) {
		bool ret = false;
		ret = checkRow(board);
		if (ret)
			return ret;

		ret = checkCol(board);
		if (ret)
			return ret;

		ret = checkCross(board);
		return ret;

	}
};
int main()
{
	Board b;
	vector<vector<int>> v = { {1,1,0},{0,1,-1},{1,0,1} };
	cout << b.checkWon(v) << endl;
	system("pause");
	return 0;
}
