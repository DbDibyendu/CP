#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

//! 2 pointers approach, but failed
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    string B;
    cin >> A;
    B = A;
    n = A.length();
    i = 0, j = 0;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    j = 1;
    //! Trying 2 pointers solution
    while (j < n)
    {
        if (A[j] == '0')
        {
            if (A[j - 1] == '1' || A[j - 1] == '?')
            {
                j++;
            }
            else
            {

                if (B[j - 1] == '0')
                {

                    ll t = (j - i);
                    temp += t * (t + 1) / 2;
                    i = j;
                    j++;
                }
                else
                {
                    ll t = (j - i);
                    temp--;
                    temp += t * (t + 1) / 2;
                    i = j - 1;
                }
                A = B;
            }
        }
        else if (A[j] == '1')
        {
            if (A[j - 1] == '0' || A[j - 1] == '?')
            {
                j++;
            }
            else
            {
                if (B[j - 1] == '1')
                {

                    ll t = (j - i);
                    temp += t * (t + 1) / 2;
                    i = j;
                    j++;
                }
                else
                {
                    ll t = (j - i);
                    temp--;
                    temp += t * (t + 1) / 2;
                    i = j - 1;
                }
                A = B;
            }
        }
        else
        {
            if (A[j - 1] == '1')
            {
                A[j] = '0';
            }
            else if (A[j - 1] == '0')
            {
                A[j] = '1';
            }
            j++;
        }
        // deb(temp);
    }
    // deb(t2);
    ll t = (j - i);
    temp += t * (t + 1) / 2;
    // i = j - 1;
    // t2 = j;
    cout << temp << endl;
}

//! DP approach
//! This question was tooo easy, but couldn't solve during contest..... was stuck on 2 pointers appraoch
void solve2()
{
    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> A;
    n = A.length();
    ll dp[n + 1][2];
    clr(dp);

    dp[0][0] = 0;
    dp[0][1] = 0;
    i = 0;
    for (i = 1; i <= n; i++)
    {
     
        if (A[i - 1] == '?')
        {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else if (A[i - 1] == '0')
        {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = 0;
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = 0;
        }
        temp += max(dp[i][0], dp[i][1]);
        // deb(temp);
    }
    cout << temp << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================