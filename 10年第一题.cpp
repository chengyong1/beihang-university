//
// Created by 程勇 on 2018/6/14.
//
/*
利用泰勒公式求cos(x)=1-x2/2!+x4/4!-……公式已给，
重要的就是注意细节（比如阶乘的存储最好用double类型），二级C语言的难度	。
 */
#include <bits/stdc++.h>
using namespace std;

double jiecheng(int n)
{
    if(n==0 or n==1)
        return 1;
    else
        return n*jiecheng(n-1);
}
double res(double x)
{
    double sum=0;
    for (int i = 0; i < 10; ++i) {
        int n = 2*i;
        if(i%2==0) sum += pow(x, n)/jiecheng(n);
        if(i%2==1) sum -= pow(x, n)/jiecheng(n);
    }
    return sum;
}
int main()
{
    double x;
    cin >> x;
    cout << res(x) << endl;
    return 0;
}
