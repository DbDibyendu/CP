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
//=======================

//!solved with brute force
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A, B;
    cin >> A >> B;
    if (A.length() > B.length())
    {
        swap(A, B);
    }
    n = A.length();
    m = B.length();
    ll max = 0;
    fo(i, 0, n)
    {
        flag = 1;
        for (j = n - i; j >= 1; j--)
        {
            // deb(A.substr(i, j));
            if (B.find(A.substr(i, j)) != string::npos)
            {
                if (A.substr(i, j).length() > max)
                {
                    max = j;
                }
            }
        }
        // deb(max);
    }
    // deb(max);
    cout << (n - max) + (m - max) << endl;
}

//! Solving with dp
//! Longest common substring
void solve2()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A, B;
    cin >> A >> B;

    m = A.length();
    n = B.length();
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].

    int LCSuff[m + 1][n + 1];
    clr(LCSuff);
    int result = 0; // To store length of the
        // longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
		bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (A[i - 1] == B[j - 1])
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    deb(result);
    cout << (n + m - 2 * result) << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================