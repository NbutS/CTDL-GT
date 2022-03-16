#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++)
        {
            long long tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        long long tong = 0;
        while (pq.size() >= 2)
        {
            long long tmp1 = pq.top();
            pq.pop();
            long long tmp2 = pq.top();
            pq.pop();
            long long sum = (tmp1 + tmp2) % MOD;
            tong = (tong + sum) % MOD;
            pq.push(sum);
        }
        cout << tong << endl;
    }
}