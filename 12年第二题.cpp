//
// Created by 程勇 on 2018/6/9.
//

/*
 * 小岛面积
       1 1 1 1 1 1
       1 1 0 0 0 1
       1 0 0 0 1 0
       1 1 0 1 1 1
       0 1 0 1 0 0
       1 1 1 1 1 1
上面矩阵的中的1代表海岸线，0代表小岛。求小岛面积（即被1中包围的0的个数）。
注意：仅求这样的0，该0所在行中被两个1包围，该0所在列中被两个1包围。
输入：
第一行输入一个整数N，表示输入方阵的维数
输入一个N维方阵
输出：
小岛面积
样例输入：
6
1 1 1 1 1 1
1 1 0 0 0 1
1 0 0 0 1 0
1 1 0 1 1 1
0 1 0 1 0 0
1 1 1 1 1 1
样例输出：
8
*/

#include <bits/stdc++.h>
using namespace std;

bool isLand(int n, vector<vector<int>> a, int i, int j)
{
    int a1=0, a2=0, a3=0, a4=0;
    for (int k = 0; k < j; ++k) {
        if(a[i][k]==1)
            a1++;
    }

    for (int k = j; k < n; ++k) {
        if(a[i][k]==1)
            a2++;
    }
    for (int l = 0; l < i; ++l) {
        if(a[l][j]==1)
            a3++;
    }
    for (int l = i; l < n; ++l) {
        if(a[l][j]==1)
            a4++;
    }
    if(a1>0 && a2>0 && a3>0 && a4>0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a;
    vector<int> temp;
    int count=0;
    for (int i = 0; i < n; ++i) {
        temp.clear();
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            temp.push_back(b);
        }
        a.push_back(temp);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==0)
                if(isLand(n, a, i, j))
                    count++;
        }
    }
    cout << count << endl;
    return 0;
}
