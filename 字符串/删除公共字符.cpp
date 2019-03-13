/*输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”*/

#include<iostream>
#include<string>
using namespace std;
//思路：要获得两个输入的字符串（可能带空格），要使用getline而不是cin，因为cin遇到空格
//就结束了。
//这里使用哈希映射思想先str2映射到hashtable上，然后用s1的各个字符去hashtable中找，很方便
//不推荐使用erase功能，一边erase一遍遍历很容易出错！
int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    
    int hashtable[256] = {0};
    for (size_t i = 0;i < s2.size();i++)//对s2依次进行hash计算，后面比对方便
    {
        hashtable[s2[i]]++;
    }
    string ret;
    for (size_t i = 0;i < s1.size();i++)
    {
        if (hashtable[s1[i]] == 0)
            ret += s1[i];
    }
    cout<<ret<<endl;
    
    return 0;
}