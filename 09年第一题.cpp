//
// Created by 程勇 on 2018/6/14.
//
/*
立方根的逼近迭代方程是 y(n+1) = y(n)*2/3 + x/(3*y(n)*y(n)),其中y0=x.
求给定的x经过n次迭代后立方根的值。
输入：
输入有多组数据。
每组一行，输入x n。
输出：
迭代n次后的立方根，double精度,保留小数点后面六位。
样例输入：
3000000 28
样例输出：
144.224957

 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double y;
    y = x;
    for(int i=1; i<=n; i++)
    {
        y = y*2/3+x/(3*y*y);
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << y << endl;
    return 0;
}
