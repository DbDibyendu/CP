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
const int N = 305, M = N;
//=======================

// ! attempt 1
int solve(vi A)
{

    int total = accumulate(A.begin(),
                           A.end(), 0);

    if (total % 3)
    {
        return -1;
    }

    int K = total / 3;

    if (K == 0)
    {
        return (int)A.size() - 1;
    }

    vi gap;
    int S = 0;

    for (int i = 0; i < A.size(); i++)
    {
        int x = A[i];
        if (x)
        {
            S += x;
            if (S == 1 or S == K + 1 or S == 2 * K + 1)
            {
                gap.push_back(i);
            }
            if (S == K or S == 2 * K or S == 3 * K)
            {
                gap.push_back(i);
            }
        }
    }

    int i1 = gap[0], j1 = gap[1],
        i2 = gap[2], j2 = gap[3],
        i3 = gap[4], j3 = gap[5];

    vi a(A.begin() + i1, A.begin() + j1 + 1);
    vi b(A.begin() + i2, A.begin() + j2 + 1);
    vi c(A.begin() + i3, A.begin() + j3 + 1);

    if (!((a == b) && (b == c)))
    {
        return -1;
    }

    int x = i2 - j1 - 1;
    int y = i3 - j2 - 1;
    int z = A.size() - j3 - 1;

    if (x < z or y < z)
    {
        return -1;
    }

    j1 += z;
    j2 += z;
    return j1;
}

ll fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = a * 1ll * a % MOD;
            p /= 2;
        }
        else
        {
            res = res * 1ll * a % MOD;
            p--;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi A(n);
        int i;
        fo(i, 0, n)
        {
            cin >> A[i];
        }

        int ans = solve(A);

        if (ans == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            ll temp = 0;
            ll t = 0;
            // deb(it);
            for (i = ans; i >= 0; i--)
            {
                if (A[i] == 1)
                    temp += fast_pow(2, t) % MOD;
                // deb(temp);
                temp %= MOD;
                t++;
            }
            cout << temp << endl;
        }
        // cout << endl;
    }
    return 0;
}
