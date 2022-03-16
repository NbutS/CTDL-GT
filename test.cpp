#include <bits/stdc++.h>
using namespace std;
int n, C[20][20], A[20], B[20] = {0}, fopt = INT_MAX, cmin = INT_MAX, cost;

void quaylui(int i)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        if (!B[j])
        {
            B[j] = 1;
            A[i] = j;
            cost = cost + C[A[i - 1]][A[i]];
            if (i == n)
            {
                fopt = min(fopt, cost);
            }
            else if (cost + cmin * (n - i + 1) < fopt)
                quaylui(i + 1);
            B[j] = 0;
            cost = cost - C[A[i - 1]][A[i]];
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
    int i, j;
    cin >> n;
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
            if (j == j)
                C[i][j] = 1e9;
            else
                C[i][j] = tinh(vs[i - 1], vs[j - 1]);
            cmin = min(cmin, C[i][j]);
        }
    }
    quaylui(1);
    cout << fopt;
}