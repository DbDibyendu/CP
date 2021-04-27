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

//! Data structures, needed good implementation skills
void solve()
{

    int i, j, n, m, k = -1, k2 = -1, k3, t;
    ll temp = 0, flag = 0;
    cin >> n >> m;
    int I[n];
    int F[n];
    int P[m];
    fo(i, 0, n)
    {
        cin >> I[i];
    }
    vi needed[n + 1];
    vi not_needed[n + 1];
    fo(i, 0, n)
    {
        cin >> F[i];
        if (I[i] != F[i])
        {
            needed[F[i]].pb(i);
        }
        else
        {
            not_needed[F[i]].pb(i);
        }
    }
    fo(i, 0, m)
    {
        cin >> P[i];
    }
    // deb2(needed[P[m - 1]].empty(), not_needed[P[m - 1]].empty());
    if (needed[P[m - 1]].empty() && not_needed[P[m - 1]].empty())
    {
        cout << "NO" << endl;
        return;
    }
    int waste = 0;
    if (!needed[P[m - 1]].empty())
    {
        waste = needed[P[m - 1]].front();
    }
    else
    {
        waste = not_needed[P[m - 1]].front();
    }
    vi ans;
    fo(i, 0, m)
    {
        if (!needed[P[i]].empty())
        {
            int t = needed[P[i]].back();
            ans.pb(t);
            needed[P[i]].pop_back();
        }
        else
        {
            ans.pb(waste);
        }
    }
    fo(i, 0, n)
    {
        if (needed[F[i]].empty())
        {
            continue;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto x : ans)
    {
        cout << x + 1 << " ";
    }
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

/* Final check before submit :
 
1. array size or integer overflow,like uninitialised 0 index.
 
2. Think twice,code once.check all possible counter test case.
 
3. Be careful about corner case! n=1?k=1? something about 0?
 
4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?
 
5. if got WA than remember that you are missing something common.
   *** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;
 
*/

/* IF WA???
 
1. corner case! n=1?k=1? something about 0?
 
2. check code(avoid stupid mistake)
 
3. read the statement again(if there any missing point???)
 
4. check the idea(check all possible counter test case again!!!)
 
5. be calm,don't be panic!!!.(***this problem not going to decide your future***)
 
6. don't waste too much time. move to next problem
 
*/