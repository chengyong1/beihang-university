//
// Created by 程勇 on 2018/6/14.
//
/*
两个整数数组（无序，可有重复元素），判断两个整数数组是否完全相同（重复元素的话，重复次数也要相同）
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s, t;
    for (int j = 0; j < n; ++j) {
        int item;
        cin >> item;
        s.push_back(item);
    }
    for (int j = 0; j < n; ++j) {
        int item;
        cin >> item;
        t.push_back(item);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s.size()!=t.size())
        cout << "not equal!" << endl;
    else
    {
        int flag=0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]!=t[i])
                flag=1;
        }
        if(flag==1)
            cout << "not equal!" << endl;
        if(flag==0)
            cout << "equal!" << endl;
    }
    return 0;
}
