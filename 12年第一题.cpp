//
// Created by 程勇 on 2018/6/9.
//
/*
 * 某些整数能分解成若干个连续整数的和的形式，例如
    15 = 1 + 2＋3＋4＋5　
    15 = 4 + 5 + 6
    15 = 7 + 8
某些整数不能分解为连续整数的和，例如：16
输入：一个整数N（N <= 10000）
输出：整数N对应的所有分解组合，按照每个分解中的最小整数从小到大输出，每个分解占一行，
每个数字之间有一个空格（每行最后保留一个空格）；如果没有任何分解组合，则输出NONE。
*/

//[i, i+1, ... , j]求和公式为S=(a1+an)*n/2;这里n=j-i+1,故S=(i+j)*(j-i+1)/2
#include <iostream>
using namespace std;

void diverse(int N)
{
    int find = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int sum = (i+j)*(j-i+1)/2;
            if(sum==N)
            {
                find = 1;
                cout << N << " = ";
                for (int k = i; k < j; ++k) {
                    cout << k << " + ";
                }
                cout << j << " ";
                cout << endl;
            }
        }
    }
    if(find==0)
        cout << "NONE" << endl;
}

int main()
{
    int N;
    cin >> N;
    diverse(N);
    return 0;
}
