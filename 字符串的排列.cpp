class Solution {
public:
    vector<string> result;
    void func(string str,int flag)
    {
        if (flag == str.size()-1)//只剩一个字符的时候结束递归
        {
            result.push_back(str);
            
        }
        int i = flag;
        for (;i <str.size();++i)//递归的循环过程，就是从每个子串的第二个字符开始依次与第一个字符交换，然后继续处理子串
        {
            if(i != flag && str[i] == str[flag])//去重
                continue;
            
            swap(str[i],str[flag]);//
            func(str,flag+1);
            swap(str[i],str[flag]);
            
        }
        
    }
    
    vector<string> Permutation(string str) {
        if (str.empty())
            return result;
       
        func(str,0);
        sort(result.begin(),result.end());//排序
        return result;
    }
};