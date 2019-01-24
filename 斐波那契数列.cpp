class Solution {
public:
    int Fibonacci(int n) {
        //如果是第0项和第一项直接返回。
        if (n==0)
        {
            return 0;
        }
        else if (n==1)
        {
            return 1;
        }

        int prev = 1;//前一项
        int ret = 1;//当前项

        for (int i = 2;i<n;i++)//迭代
        {
            int tmp = ret;
            ret += prev;
            prev = tmp;
        }
        return ret;
    }
};