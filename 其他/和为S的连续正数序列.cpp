/*题目：
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序*/

/*思路：我们要找出所有和为s的序列，一开始我们以{1，2}作为最初始的序列。当这个序列的和小于S时，我们就让尾扩大一点，变成{1，2，3}.
而倘若序列的值大于S，我们让序列的头缩小一点，变成{2，3}。每次变化后都去比较，等于S后加入到结果集中。
循环结束的条件是当头尾相遇的时候，这时候说明序列不能放任何一个值 了，任何一个都比S大。
 */
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> vv;
        int begin = 1;
        int end = 2;
        while (end > begin)
        {
            int tmp = (begin + end) * (end - begin + 1) / 2;
            if (tmp == sum)
            {
                vector<int> v;
                for (int i = begin;i <= end ; i++)
                    v.push_back(i);
                vv.push_back(v);
                end++;
            }
            else if (tmp > sum)
                begin++;
            else
                end++;
        }
        return vv;
    }
};