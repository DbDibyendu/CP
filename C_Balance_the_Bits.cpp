//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;

bool isBalanced(string expr)
{
    stack<char> s;
    char ch;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(')
        {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
            return false;
        switch (expr[i])
        {
        case ')':
            s.pop();
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    string T;
    cin >> T;
    if (T[0] != T[n - 1] || T[0] != '1')
    {

        cout << "NO" << endl;
        return;
    }
    int one = 0;
    fo(i, 1, n - 1)
    {
        if (T[i] == '0')
        {
            temp++;
        }
        else
        {
            one++;
        }
    }
    if (temp & 1)
    {
        cout << "NO" << endl;
        return;
    }
    string A, B;
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
    fo(i, 0, n)
    {
        if (i == 0)
        {
            A += '(';
            B += '(';
            continue;
        }
        else if (i == n - 1)
        {
            A += ')';
            B += ')';
            continue;
        }
        A += '(';
        B += '(';
        if (T[i] == '0')
        {
            if (l1)
            {
                A[i] = ')';
            }
            else
            {
                B[i] = ')';
            }
            l1 = l1 ^ 1;
        }
        else
        {
            if (r1)
            {
                A[i] = ')';
                B[i] = ')';
            }
            r1 ^= 1;
        }
    }
    cout << "YES" << endl;

    cout << A;

    cout << endl;

    cout << B;

    cout << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================