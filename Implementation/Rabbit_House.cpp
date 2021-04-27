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
const int N = 305, M = N;
//=======================

//! Tough implementation
// !djiksa algorithm
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    ll r, c;
    cin >> r >> c;
    ll A[N][N];
    int dx[4] = {1, 0, -1, 0}; //? Direction pairs in 4 direction
    int dy[4] = {0, 1, 0, -1};

    set<pair<int, pll>> maxH; //! Used set pair
    fo(i, 1, r + 1)
    {
        fo(j, 1, c + 1)
        {
            cin >> A[i][j];
            maxH.insert({-A[i][j], {i, j}});
        }
    }

    while (!maxH.empty())
    {
        auto t = *maxH.begin();
        maxH.erase(maxH.begin());
        int Height = -t.first;
        int x = t.second.first, y = t.second.second;
        // deb(Height);
        for (i = 0; i < 4; i++)
        {
            // deb(y);
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 1 || X > r || Y < 1 || Y > c)
            {
                continue; //! Skips any other functions in the loop
            }
            if (A[X][Y] >= Height - 1)
            {
                continue;
            }

            int diff = Height - A[X][Y] - 1;
            // deb(diff);
            temp += diff;
            maxH.erase({-A[X][Y], {X, Y}});
            A[X][Y] += diff;

            maxH.insert({-(A[X][Y]), {X, Y}});
        }
    }
    cout << temp << endl;
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