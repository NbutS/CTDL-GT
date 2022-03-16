#include <bits/stdc++.h>
using namespace std;
struct task
{
    int start, finish;

} a[100005];
bool compare(task a, task b)
{
    return a.finish < b.finish;
}
int main()
{
    int t, d, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].start >> a[i].finish;
        sort(a, a + n, compare);
        int i = 0;
        d = 1;
        for (int j = 1; j < n; j++)
        {
            if (a[j].start >= a[i].finish)
            {
                i = j;
                d++;
            }
        }
        cout << d << endl;
    }
}