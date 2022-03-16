#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        long long tong = 0;
        while (pq.size() >= 2)
        {
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();
            tong = tong + tmp1 + tmp2;
            pq.push(tmp1 + tmp2);
        }
        cout << tong << endl;
    }
}