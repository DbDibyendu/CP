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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

void solve()
{

    int i, j, n, m, k;  
    ll temp = 0, flag = 1;
    cin >> n >> m;

    vector<pair<ll, ll>> B(m + 1);
    vl A(n + 1);

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> B[i].first;
        B[i].second = 0;
    }

    sort(A.begin(), A.end(), greater<ll>());

    for (i = 0; i < n; i++)
    {

        for (j = i; j < n; j++)
        {
            if (j <= A[i] - 1 && B[j].second == 0 && j < m)
            {
                temp += B[j].first;
                B[j].second = 1;
                break;
            }
            else 
            {
                temp += B[A[i] - 1].first;
                break;
            }
        }
        //deb2(temp, k);
    }
    cout << temp << endl;
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