#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k, s;
    int temp = 0, flag = 0;
    cin >> m >> s;
    vi A(m), B(m);

    int s1 = s;
    if (s == 0 && m != 1)
    {
        cout << -1 << " " << -1 << endl;
        return;
    }
    else if (s == 0 && m == 1)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    j = 0;
    while (j < m)
    {
        temp = 0;
        for (i = 0; i <= 9; i++)
        {
            if (s >= i)
            {
                temp = max(temp, i);
            }
        }
        // deb(s);
        B[j] = temp;
        j++;
        s = s - temp;
    }
    if (s == 0)
    {

        j = 0;

        if (B[m - 1] == 0)
        {
            A[j] = 1;
            flag = 1;
        }
        else
        {
            A[j] = B[m - 1];
        }
        j++;
        for (i = m - 2; i >= 0; i--)
        {
            if (flag == 1 && B[i] > 0)
            {
                A[j] = B[i] - 1;
                flag = 0;
            }
            else if (flag == 1 && B[i] == 0)
            {
                A[j] = B[i];
            }
            else if (flag == 0)
            {
                A[j] = B[i];
            }
            j++;
        }

        fo(i, 0, m) cout << A[i];
        cout << " ";
        fo(i, 0, m) cout << B[i];
        cout << endl;
    }
    else
    {
        cout << -1 << " " << -1 << endl;
        return;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//======================