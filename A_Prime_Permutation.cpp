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

bool isPrime(int n)
{
    int i;
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> A;
    n = A.length();
    // deb(n);
    if (n <= 3)
    {
        cout << "YES" << endl;
        cout << A << endl;
        return;
    }
    int pre[1005] = {0};
    k = n / 2;
    for (j = 2; j <= k; j++)
    {
        if (isPrime(j))
            for (i = j; i <= n; i += j)
            {
                if (pre[i] == 0)
                {
                    pre[i] = 1;
                    temp++;
                }
            }
    }
    int alpha[26] = {0};
    for (i = 0; i < n; i++)
    {
        alpha[A[i] - 'a']++;
    }
    int sim_max = 0;
    int charc = 0;
    for (i = 0; i < 26; i++)
    {
        if (sim_max < alpha[i])
        {
            sim_max = alpha[i];
            charc = i;
        }
        // sim_max = max(sim_max, alpha[i]);
    }

    // deb2(temp, alpha[charc]);
    if (sim_max >= temp)
    {
        cout << "YES" << endl;
        for (i = 0; i < n; i++)
        {
            if (pre[i + 1])
            {
                alpha[charc]--;
            }
        }
        // deb2(temp, alpha[charc]);
        for (i = 0; i < n; i++)
        {
            if (pre[i + 1])
            {
                cout << (char)(charc + 'a');
            }
            else
            {
                for (j = 0; j < 26; j++)
                {
                    if (alpha[j] > 0)
                    {
                        cout << (char)(j + 'a');
                        alpha[j]--;
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================