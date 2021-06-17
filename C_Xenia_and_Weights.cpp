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

// Constructive approach
void solve()
{

    int i, n, m;
    ll temp = 0, flag = 1;
    string c;
    cin >> c;
    cin >> m;
    vl weights;

    fo(i, 0, 10)
    {
        if (c[i] == '1')
        {
            weights.pb(i + 1);
        }
    }
    if (weights.size() == 0)
    {

        cout << "NO" << endl;
        return;
    }
    if (weights.size() == 1)
    {
        if (m == 1)
        {
            cout << "YES" << endl;
            cout << weights[0] << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    //================

    ll even = 0, odd = 0;
    int last = -1, j, k = 0;
    n = weights.size();
    while (k < n - 1 && flag == 1)
    {
        //   deb(k);
        odd = 0;
        even = 0;
        last = -1;
        for (i = 0; i < m; i++)
        {
            flag = 1;
            if (i % 2 == 0)
            {
                if (i == 0)
                {
                    odd += weights[k];
                    last = k;
                    flag = 0;
                }
                else
                    for (j = 0; j < n; j++)
                    {
                        if (odd + weights[j] > even && j != last)
                        {
                            last = j;
                            odd += weights[j];
                            flag = 0;
                            // deb(weights[j]);
                            break;
                        }
                    }
                if (flag)
                {
                    k++;
                    break;
                }
            }
            else
            {
                for (j = 0; j < n; j++)
                {
                    if (even + weights[j] > odd && j != last)
                    {
                        last = j;
                        even += weights[j];
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    k++;
                    break;
                }
            }
        }
    }
    if (flag)
    {
        cout << "NO" << endl;
        return;
    }

    j = 0;
    cout << "YES" << endl;
    odd = 0;
    even = 0;
    last = -1;
    for (i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            if (i == 0)
            {
                odd += weights[k];
                last = k;
                cout << weights[k] << " ";
                flag = 0;
            }
            else
                for (j = 0; j < n; j++)
                {
                    if (odd + weights[j] > even && j != last)
                    {
                        last = j;
                        odd += weights[j];
                        cout << weights[j] << " ";
                        break;
                    }
                }
        }
        else
        {
            for (j = 0; j < n; j++)
            {
                if (even + weights[j] > odd && j != last)
                {
                    last = j;
                    even += weights[j];
                    cout << weights[j] << " ";
                    break;
                }
            }
        }
    }
}

// Dfs approach

vi ans, weights;
int m;

bool dfs(int i, int last, int value)
{

    if (i == m)
    {
        return true;
    }
    int j;
    for (j = 0; j < weights.size(); j++)
    {
        if (j != last)
        {
            if (weights[j] - value > 0 && dfs(i + 1, j, weights[j] - value))
            {
                ans.pb(weights[j]);
                return true;
            }
        }
    }
    return false;
}

void solve2()
{
    string c;
    cin >> c >> m;
    int i;
    fo(i, 0, 10)
    {
        if (c[i] == '1')
        {
            weights.pb(i + 1);
        }
    }

    if (dfs(0, -1, 0))
    {
        cout << "YES" << endl;
        for (i = m - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        return;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
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