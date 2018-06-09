题目要求：五子棋。输入一个19*19的矩阵，只包含数字0、1、2，表示两人下五子棋的棋牌状态，1、2分别表示两人的棋子，0表示空格。
要求判断当前状态下是否有人获胜（横向、竖向或者斜线方向连成5个同色棋子）。题目说明输入样例保证每条线上至多只有连续5个同色棋子，
并且保证至多只有1人获胜.如果有人获胜，输出获胜者（1或2）加一个冒号，
接着输出获胜的五连珠的第一个棋子的坐标，从上到下从左到右序号最小的为第一个，序号从1开始编号。如果无人获胜，输出no。

//
// Created by 程勇 on 2018/6/7.
//
#include <bits/stdc++.h>
using namespace std;

const int N=6;

int rowSame(int a[N][N], int &index)
{
    for (int i = 0; i < N; ++i) {
        int count1=0;
        int count2=0;
        for (int j = 0; j < N; ++j) {
            if(a[i][j]==0)
            {
                count1 = 0;
                count2 = 0;
            }
            if(a[i][j]==1)
            {
                count1++;
                count2 = 0;
            }

            if(a[i][j]==2)
            {
                count2++;
                count1 = 0;
            }
            if(count1==5) {
                index = (i+1)*N+(j+1-5);
                return 1;
            }
            if(count2==5) {
                index = (i+1)*N+(j+1-5);
                return 2;
            }
        }
    }
    return 0;
}

int colSame(int a[N][N], int &index)
{
    index = -1;
    for (int i = 0; i < N; ++i) {
        int count1=0;
        int count2=0;
        for (int j = 0; j < N; ++j) {
            if(a[j][i]==0)
            {
                count1 = 0;
                count2 = 0;
            }
            if(a[j][i]==1)
            {
                count1++;
                count2 = 0;
            }

            if(a[j][i]==2)
            {
                count2++;
                count1 = 0;
            }
            if(count1==5) {
                index = (i+1-5)*N+(j+1);
                return 1;
            }
            if(count2==5) {
                index = (i+1-5)*N+(j+1);
                return 2;
            }
        }

    }
    return 0;
}

int mux(vector<int> temp, int &index)
{
    index = -1;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < temp.size(); ++i) {
        if(temp[i]==0)
        {
            count1 = 0;
            count2 = 0;
        }
        if(temp[i]==1)
        {
            count1++;
            count2 = 0;
        }
        if(temp[i]==2)
        {
            count2++;
            count1 = 0;
        }
        if(count1==5) {
            index = i-4;
            return 1;
        }
        if(count2==5) {
            index = i-4;
            return 2;
        }
    }
    return 0;
}

int muxAll(int a[N][N], int &index)
{
    index = -1;
    int point;
    vector<int> temp;
    for (int i = 4; i < N; ++i) {
        temp.clear();
        for (int j = 0; j <= i; ++j) {
            temp.push_back(a[i-j][j]);
            int res = mux(temp, point);
            if(res==1) {
                index = (i-point)*N+point;
                return 1;
            }
            if(res==2) {
                index = (i-point)*N+point;
                return 2;
            }
        }
    }
    for (int i = 4; i < N-1; ++i) {
        temp.clear();
        for (int j = 0; j <= i; ++j) {
            temp.push_back(a[j][i-j]);
            int res = mux(temp, point);
            if(res==1) {
                index = (point)*N+i-point;
                return 1;
            }
            if(res==2) {
                index = (point)*N+i-point;
                return 2;
            }
        }
    }
    return 0;
}

int res(int a[N][N], int &index)
{
    index = -1;
    int row, col, mux;
    int ans = rowSame(a, row)+colSame(a, col)+muxAll(a, mux);
    if(row!=-1)
        index = row;
    if(col!=-1)
        index = col;
    if(mux!=-1)
        index = mux;
    if(ans==1)
        return 1;
    if(ans==2)
        return 2;
    if(ans==0)
        return 0;

}
int main()
{
    int a[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    int index;
    int anw = res(a, index);
    if(anw==1)
    {
        cout << 1 << ":" << index;
    }
    if(anw==2)
    {
        cout << 2 << ":" << index;
    }
    if(anw==0)
    {
        cout << "No";
    }
    return 0;
}
