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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    vl A(2 * n);
    vl B(n);
    set<int> s;
    fo(i, 0, 2 * n)
    {
        cin >> A[i];
        if (A[i] % 2 != 0)
        {
            temp++;
        }
        s.insert(A[i]);
    }
    if (temp)
    {
        cout << "NO" << endl;
        return;
    }
    if (s.size() != n)
    {
        cout << "NO" << endl;
        return;
    }
    sort(A.begin(), A.end());

    for (i = 0; i < 2 * n; i += 2)
    {
        B[i / 2] = A[i] / 2;
        // deb(repeat[B[i / 2]]);
    }

    ll sub = 0;
    for (i = n; i > 0; i--)
    {
        temp = B[i - 1] - sub;
        if (temp % i == 0 && temp > 0)
        {
            // deb(temp / i);
            sub += temp / i;
            // deb(sub);
            flag++;
        }
    }
    if (sub == B[0] && flag == n)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
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