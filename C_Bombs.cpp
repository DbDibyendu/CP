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


// Learnt the use of ternary operator
void solve()
{

    int i, j, n, m, k, x, y;
    ll temp = 0, flag = 1;
    cin >> n;
    vector<pair<int, pair<int, int>>> bomb;

    for (i = 0; i < n; i++)
    {
        cin >> x >> y;

        bomb.pb(make_pair(abs(x) + abs(y), make_pair(x, y)));

        if (x == 0 || y == 0)
        {
            temp += 4;
        }
        else
        {
            temp += 6;
        }
    }
    cout << temp << endl;
    sort(bomb.begin(), bomb.end());

    fo(i, 0, n)
    {
        x = bomb[i].second.first;
        y = bomb[i].second.second;
        if (abs(x))
            printf("1 %d %c\n", abs(x), x > 0 ? 'R' : 'L');
        if (abs(y))
            printf("1 %d %c\n", abs(y), y > 0 ? 'U' : 'D');
        printf("2\n");
        if (abs(x))
            printf("1 %d %c\n", abs(x), x > 0 ? 'L' : 'R');
        if (abs(y))
            printf("1 %d %c\n", abs(y), y > 0 ? 'D' : 'U');
        printf("3\n");
    }
}

void solve2()
{

    int i, j, n, m, k, x, y;
    ll temp = 0, flag = 1;
    cin >> n;
    pair<int, pair<int, int>> bomb[n];

    for (i = 0; i < n; i++)
    {
        cin >> x >> y;

        bomb[i] = make_pair(abs(x) + abs(y), make_pair(x, y));

        if (x == 0 || y == 0)
        {
            temp += 4;
        }
        else
        {
            temp += 6;
        }
    }
    sort(bomb, bomb + n);
    cout << temp << endl;

    fo(i, 0, n)
    {
        x = bomb[i].second.first;
        y = bomb[i].second.second;
        if (abs(x))
            printf("1 %d %c\n", abs(x), x > 0 ? 'R' : 'L');
        if (abs(y))
            printf("1 %d %c\n", abs(y), y > 0 ? 'U' : 'D');
        printf("2\n");
        if (abs(x))
            printf("1 %d %c\n", abs(x), x > 0 ? 'L' : 'R');
        if (abs(y))
            printf("1 %d %c\n", abs(y), y > 0 ? 'D' : 'U');
        printf("3\n");
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