#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
void xuly()
{
    int k;
    cin >> k;
    cin.ignore();
    string s;
    cin >> s;
    int b[100] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        b[s[i]]++;
    }
    priority_queue<int> pq;
    for (int i = 0; i < 100; i++)
    {
        if (b[i] != 0)
            pq.push(b[i]);
    }
    int check = 0;
    while (k > 0)
    {
        if (pq.top() == 0)
        {
            check = 1;
            break;
        }
        if (check == 1)
            break;
        int tmp = pq.top();
        tmp--;
        k--;
        pq.pop();
        pq.push(tmp);
    }
    long long tong = 0;
    while (pq.size())
    {
        tong += pq.top() * pq.top();
        pq.pop();
    }
    cout << tong << endl;
}
int main()
{
    faster int t;
    cin >> t;
    while (t--)
        xuly();
    return 0;
}