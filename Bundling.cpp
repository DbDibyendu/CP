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
const int N = 1e6 * 2, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    map<string, ll> hash;
    string A;
    fo(i, 0, n)
    {
        cin >> A;
        hash[A]++;
    }
    m = k;
    char compare[N];
    clr(compare);
    ll sum = 0;
    ll grp = MOD;
    for (auto x : hash)
    {
        ll t = x.second;
        fo(j, 0, t)
        {
            if (k == 0)
            {
                sum += grp;
                grp = MOD;
                //  cout << endl;
                k = m;
                ll n1;
                n1 = x.first.size();
                temp = 0;
                for (i = 0; i < n1; i++)
                {
                    if (k == m)
                    {
                        compare[i] = x.first[i];
                    }
                    else
                    {
                        if (compare[i] == x.first[i])
                        {
                            temp++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // deb2(temp, x.first);
                if (temp)
                    grp = min(grp, temp);
                k--;
            }
            else
            {
                ll n1;
                n1 = x.first.size();
                temp = 0;
                for (i = 0; i < n1; i++)
                {
                    if (k == m)
                    {
                        compare[i] = x.first[i];
                    }
                    else
                    {
                        if (compare[i] == x.first[i])
                        {
                            temp++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // deb2(temp, x.first);
                if (temp)
                    grp = min(grp, temp);
                k--;
                continue;
            }
        }
        if (k == 0)
        {
            sum += grp;
            grp = MOD;
            // cout << endl;
            k = m;
        }
    }
    if (sum >= MOD)
        cout << 0 << endl;
    else
        cout << sum << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================