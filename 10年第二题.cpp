//
// Created by 程勇 on 2018/6/14.
//
/*
归并两个有序字符串，要求输出不能有重复字符（数据结构上做过N遍的Merge函数）
 */
#include <bits/stdc++.h>
using namespace std;

void strMarge(string s, string t)
{
    int i=0, j=0, k=0;
    while(j<s.length() and k<t.length())
    {
        if(s[j]>t[k])
            cout << t[k++];
        else
            cout << s[j++];
    }
    while(j<s.length())
    {
        cout << s[j++];
    }
    while(k<t.length())
    {
        cout << t[k++];
    }
}
int main()
{
    string s, t;
    cin >> s >> t;
    strMarge(s, t);
    return 0;
}
