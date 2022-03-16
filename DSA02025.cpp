#include <bits/stdc++.h>
using namespace std;
int n, c[20][20], a[20], b[20] = {0}, fopt = INT_MAX, cmin = INT_MAX, cost;
void quaylui(int i)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        if (!b[j])
        {
            b[j] = 1;
            a[i] = j;
            cost = cost + c[a[i - 1]][a[i]];
            if (i == n)
            {
                fopt = min(fopt, cost);
            }
            else if (cost + cmin * (n - i + 1) < fopt)
                quaylui(i + 1);
            b[j] = 0;
            cost = cost - c[a[i - 1]][a[i]];
        }
    }
}
int tinh(string s1, string s2)
{
    int i = 0, j = 0, d = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
            d++;
        }
        else if (s1[i] < s2[j])
            i++;
        else
            j++;
    }
    return d;
}
int main()
{
    cin >> n;
    int j, i;
    vector<string> vs;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vs.push_back(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                c[i][j] = 1e9;
            else
                c[i][j] = tinh(vs[i - 1], vs[j - 1]);
            cmin = min(cmin, c[i][j]);
        }
    }

    quaylui(1);
    cout << fopt;
}
