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

    int i, j, n, m, k = -1, k2 = -1, k3, t;
    ll temp = 0, flag = 0;
    cin >> n >> m;
    unordered_map<int, int> MAP;
    vl A(n), B(n), C(m);
    fo(i, 0, n) cin >> A[i];
    fo(i, 0, n)
    {
        cin >> B[i];
        MAP[B[i]]++;
    }
    fo(i, 0, m) cin >> C[i];

    if (MAP[C[m - 1]] == 0)
    {
        cout << "NO" << endl;
        return;
    }

    vl Ans;
    fo(j, 0, n)
    {
        if (C[m - 1] == B[j])
        {
            k3 = j;
        }
    }
    fo(i, 0, m)
    {
        flag = 0;
        fo(j, 0, n)
        {
            if (C[i] == B[j] && j != k3)
            {
                if (A[j] != B[j])
                {
                    flag = 1;
                    A[j] = B[j];
                    Ans.pb(j + 1);
                    break;
                }
            }
            if (flag == 0 && j == n - 1)
            {

                A[k3] = C[i];
                Ans.pb(k3 + 1);
                break;
            }
        }
    }

    fo(i, 0, n)
    {
        if (A[i] != B[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (auto x : Ans)
    {
        cout << x << " ";
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