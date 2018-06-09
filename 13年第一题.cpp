题目要求：给一个真分数的分子分母，输出约分后的分子分母。
//
// Created by 程勇 on 2018/6/9.
//
#include <iostream>
using namespace std;

void reduction(int a, int b)
{
    int temp=0;
    while(temp!=1)
    {
        for(int i=1; i<=a; i++)
        {
            if(a%i==0 and b%i==0)
            {
                temp = i;
                a = a/i;
                b = b/i;
            }
        }
    }
    cout << a << " " << b;
}
int main()
{
    reduction(10, 15);
    return 0;
}
