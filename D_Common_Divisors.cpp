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

// ! Simple concept, smart implementation

bool isD(string a, string b)
{
    if (a.size() % b.size() != 0)
    {
        return false;
    }
    ll i;

    for (i = 0; i < a.size(); i += b.size())
    {

        if (a.substr(i, b.size()) != b)
        {
            return false;
        }
    }

    return true;
}
void solve()
{

    ll i, j, k;
    ll temp = 0, flag = 1;
    string a, b;
    map<string, ll> hash;
    cin >> a >> b;

    ll n = a.size();
    ll m = b.size();
    set<string> ans;

    for (i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
        {
            continue;
        }
        else
        {
            string A = a.substr(0, i);
            string B = a.substr(0, n / i);

            if (isD(a, A))
            {
                ans.insert(A);
            }
            if (isD(a, B))
            {
                ans.insert(B);
            }
        }
    }

    for (auto x : ans)
    {
        if (isD(b, x))
        {
            temp++;
        }
    }
    cout << temp << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================