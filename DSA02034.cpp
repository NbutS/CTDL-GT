#include <bits/stdc++.h>
using namespace std;
int n, a[15], b[15], check[15];
bool Check()
{
    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i] - a[i - 1]) == 1)
            return false;
    }
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i + 1]) == 1)
            return false;
    }
    return true;
}
void in()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
void quaylui(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (check[j] == 0)
        {
            a[i] = j;
            check[j] = 1;
            if (i == n)
            {
                if (Check())
                    in();
            }
            else
                quaylui(i + 1);
            check[j] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        check[15] = {0};
        quaylui(1);
    }
}