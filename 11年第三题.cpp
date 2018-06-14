//
// Created by 程勇 on 2018/6/14.
//
/*
从键盘输入包含扩展符'-'的字符串，将其扩展为等价的完整字符，例如将a-d扩展为abcd，并输出扩展后的字符串。
要求：只处理[a-z]、[A-Z]、[0-9]范围内的字符扩展，即只有当扩展符前后的字符同时是小写字母、
大写字母或数字时才进行扩展，其它情况不进行扩展，原样输出。例如：a-R、D-e、0-b、4-B等字符串都不进行扩展。
【输入形式】
从键盘输入包含扩展符的字符串
【输出形式】
输出扩展后的字符串
【输入样例1】
ADEa-g-m02
【输出样例1】
ADEabcdefghijklm02
【输入样例2】
cdeT-bcd
【输出样例2】
cdeT-bcd
【样例说明】
将样例1的输入ADEa-g-m02扩展为：ADEabcdefghijklm02；
样例2的输入cdeT-bcd中，扩展符前的字符为大写字母，扩展符后的字符为小写字母，
不在同一范围内，所以不进行扩展。
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i=1; i<s.length(); i++)
    {
        cout << s[i-1];
        if(s[i]=='-')
        {
            if(s[i-1]>='a' and s[i+1]<='z')
            {
                for(char ch=s[i-1]+1; ch<s[i+1]; ch++)
                {
                    cout << ch;
                }
                i++;
            }
            else if(s[i-1]>='A' and s[i+1]<='Z')
            {
                for(char ch=s[i-1]+1; ch<s[i+1]; ch++)
                {
                    cout << ch;
                }
                i++;
            }
            else if(s[i-1]>='0' and s[i+1]<='9')
            {
                for(char ch=s[i-1]+1; ch<s[i+1]; ch++)
                {
                    cout << ch;
                }
                i++;
            }
        }
    }
    cout << s[s.length()-1] << endl;
    return 0;
}
