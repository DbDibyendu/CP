#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fill(x, y) memset(x, y, sizeof(x))
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ff(j, n) for (int i = j; i < n; i++)
#define fb(j, n) for (int i = n - 1; i >= j; i--)
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int b[n];
        ff(0, n)
        {
            cin >> b[i];
        }
        long long int j = 1;
        long long int ans = 1;
        int f[n][n] = {0};
        f[0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int i1 = 0; i1 <= i; i1++)
            {
                if (i1 < b[i])
                {
                    f[i][i1] = f[i - 1][i1] + i1;
                }
                else
                {
                    for (int i3 = 0; i < b[i] - 1; i3++)
                    {
                        f[i][i3]++;
                    }
                }
            }
            f[i][i + 1] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            ans += f[n - 1][i];
            ans % 1000000007;
        }
        cout << ans << endl;
    }
    return 0;
}