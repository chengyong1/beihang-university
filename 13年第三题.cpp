题目要求：给出一个标准输入的正数（开头末尾没有多余的0），输出其科学计数法表示结果。
比如：输入0.000002，输出2e-6；输入123.456，输出1.23456e2；输入123456，输出1.23456e2

//
// Created by 程勇 on 2018/6/9.
//
#include <bits/stdc++.h>
using namespace std;

string bigOne(string S)
{
    string temp;
    string exponece;
    int dotIndex = 0;
    while(S[dotIndex]!='.')
    {
        dotIndex++;
    }
    exponece = dotIndex-1+'0';
    temp += S[0];
    temp += '.';
    for (int i = 1; i < S.length(); ++i) {
        if(S[i]!='.')
            temp += S[i];
    }
    temp += 'e';
    temp += exponece;
    return temp;
}

string smallOne(string S)
{
    string temp;
    string exponece;
    int noZeroIndex=2;
    while(S[noZeroIndex]=='0')
    {
        noZeroIndex++;
    }
    exponece = noZeroIndex-1+'0';
    temp += S[noZeroIndex];
    temp += '.';
    for(int i=noZeroIndex+1; i<S.length(); i++)
    {
        temp += S[i];
    }
    temp += 'e';
    temp += '-';
    temp += exponece;
    return temp;
}

string res(string S)
{
    string anw;
    int dotIndex=0;
    while(S[dotIndex]!='.')
    {
        dotIndex++;
    }
    if(dotIndex==1)
        if(S[0]=='0')
            anw = smallOne(S);
        else
            anw = bigOne(S);
    else
        anw = smallOne(S);
    return anw;
}
int main()
{
    string S;
    cin >> S;
    cout << res(S);
}

