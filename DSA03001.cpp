#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, s, Min;
int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
void ATM(int i, int dem, int d)
{
    if (dem > s || d > Min)
        return;
    if (i == n)
    {
        if (dem == s && d < Min)
            Min = d;
        return;
    }
    ATM(i + 1, dem, d);
    ATM(i + 1, dem + a[i], d + 1);
}
int main()
{

    priority_queue<int, vector<int>, greater<int>> qq;
    qq.push(5);
    qq.push(2);
    cout << qq.top();
}