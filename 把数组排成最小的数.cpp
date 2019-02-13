/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。


思路：学习到了一个新函数 to_string，很方便，可以将各种类型的数字转称字符串。
本题中要求最小的数字，为了得到数字我们需要对各个数进行拼接，如果按照数值进行拼接，不方便且可能会出现超过整型上限的问题。
所以，将数字转称字符串，然后进行拼接即可。




这里sort的第三个参数可以自定义比较！！！！
*/
class Solution {
public:
    static bool cmp(int a,int b)//自定义比较函数，用于将numbers内的整型按照字符串比较大小的方式进行排序
    {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        
        return s1 < s2;
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);//对numbers各个数进行排序
        
        string result;
        int size = numbers.size();
        
        for (int i = 0;i < size;i++)//挨个加jiu'ke'yi
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};
