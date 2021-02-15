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

    ll i, j, n, m, k, x, a;
    ll temp = 0, flag = 1, task, last2 = 0, last1 = 0;
    cin >> n;
    float ans[n];
    vl A;
    ll val[n + 1];
    clr(val);
    A.pb(0);
    fo(i, 0, n)
    {
        cin >> task;
        if (task == 1)
        {

            cin >> a >> x;
            temp += a * x;
            val[a - 1] += x;
        }
        else if (task == 2)
        {
            cin >> x;
            A.push_back(x);
            temp += x;
            flag++;
        }
        else if (task == 3)
        {
            if (flag)
            {
                temp -= A.back();
                temp -= val[flag - 1];
                if (flag - 2 >= 0)w
                    val[flag - 2] += val[flag - 1];
                val[flag - 1] = 0;    // ! I missed this, Avoid this type of silly mistake
                A.pop_back();
                flag--;
            }
        }
        printf("%.6lf \n", (double)temp / (double)flag);
    }
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