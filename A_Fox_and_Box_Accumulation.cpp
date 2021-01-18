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
    ll temp = 0, flag = 1, cap = 0;
    cin >> n;
    vi A(n);
    int El[101] = {};
    int count[105] = {};
 
    fo(i, 0, n)
    {
        cin >> A[i];
        El[A[i]]++;
    }
 
    sort(A.begin(), A.end());
    i = 0;
    k = 1;
    while (n > 0)
    {
        k = 1;
        while (El[A[i]] > 0)
        {
            if (A[i] < count[k])
            {
                k++;
            }
            count[k]++;
            El[A[i]]--;
            n--;
        }
        i++;
        if (k > temp)
        {
            temp = k;
        }
    }
 
    cout << temp << endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================