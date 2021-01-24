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
    ll temp = 0, flag = 1;
    cin >> n;
    vl nums(2 * n, 0);
    multiset<ll, greater<ll>> S;

    fo(i, 0, 2 * n)
    {
        cin >> nums[i];
        S.insert(nums[i]);
    }
    sort(nums.begin(), nums.end());

    int x, y, z;
    for (i = 0; i < 2 * n - 1; i++)
    {
        x = nums[2 * n - 1] + nums[i];
        multiset<ll, greater<ll>> tempS;
        vpll ans;
        tempS = S;
        flag = 0;
        int init = x;
        while (!tempS.empty())
        {
            int y = *tempS.begin();
            tempS.erase(tempS.begin());
            int z = x - y;
            if (tempS.find(z) != tempS.end())
            {
                ans.push_back({y, z});
                tempS.erase(tempS.find(z));
                x = max(y, z);
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "YES" << endl;
            cout << init << endl;

            for (auto it : ans)
            {
                cout << it.first << " " << it.second << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
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