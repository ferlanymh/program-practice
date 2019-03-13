class Solution {
public:
    void printCircle(vector<vector<int>>& matrix,vector<int>& result,int &start,
                         int &row,int &col)
    {
        int endX = row - 1 - start;//当前圈的边界行号
        int endY = col - 1 - start;//当前圈的边界列号
        //肯定要先打印从左到右的一行。
        for (int i = start;i <= endY;i++)
        {
            result.push_back(matrix[start][i]);
        }
        
        //打印从上到下的一列的前提是有至少2行
        if (endX > start)
        {
            for (int i = start+1;i <= endX;i++)
            {
                 result.push_back(matrix[i][endY]);
            }
        }
        //打印从右到左的一列的前提是2行2列
        if (endX > start && endY > start)
        {
            for (int i = endY-1 ;i >= start;i--)
            {
                result.push_back(matrix[endX][i]);
            }
        }
        //打印从下到上的一行的前提是有3行2列
        if ((start < endX - 1 ) && endY > start)
        {
            for (int i = endX-1;i >= start+1;i--)
            {
                result.push_back(matrix[i][start]);
            }
        }
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if (matrix.empty())//为空则返回
            return result;
        
        int row = matrix.size();//行和列
        int col = matrix[0].size();
        int start = 0;//起始坐标
        //将打印矩形拆分成打印数圈
        //根据规律发现每次要打印一圈的前提条件是圈的起始坐标的2倍小于总行数和列数
        while ((row > 2*start) && (col > 2*start))
        {
            printCircle(matrix,result,start,row,col);
            start++;
        }
       
        return result;
    }
    
};