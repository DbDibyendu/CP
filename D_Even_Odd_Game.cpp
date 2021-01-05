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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll alice = 0, bob = 0;
    cin >> n;
    vl A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (i = n - 1; i >= 0; i--)
    {
        if (A[i] % 2 == 0 && flag == 1)
        {
            alice += A[i];
            flag = 0;
        }
        else if (A[i] % 2 != 0 && flag == 1)
        {
            flag = 0;
        }
        else if (A[i] % 2 != 0 && flag == 0)
        {
            bob += A[i];
            flag = 1;
        }
        else if (A[i] % 2 == 0 && flag == 0)
        {

            flag = 1;
        }
    }
    if (bob > alice)
    {
        cout << "Bob" << endl;
    }
    else if (alice > bob)
        cout << "Alice" << endl;
    else
        cout << "Tie" << endl;
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