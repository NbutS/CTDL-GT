#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, d;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> d >> s;
        int a['z' + 1] = {0};
        n = s.size();
        for (int i = 0; i <= n; i++)
        {
            a[s[i]]++;
        }
        int m = *max_element(a, a + 'z');
        if ((m - 1) * d < n)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
}