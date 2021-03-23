
//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯
//!          `\-.   `
//!                       \ `.  `
//!                        \  \ |
//!               __.._    |   \.       S O N - G O K U
//!        ..---~~     ~ . |    Y
//!          ~-.          `|    |
//!             `.               `~~--.
//!               \                    ~.
//!                \                     \__. . -- -  .
//!          .-~~~~~      ,    ,            ~~~~~~---...._
//!       .-~___        ,'/  ,'/ ,'\          __...---~~~
//!             ~-.    /._\_( ,(/_. 7,-.    ~~---...__
//!            _...>-  P""6=`_/"6"~   6)    ___...--~~~
//!             ~~--._ \`--') `---'   9'  _..--~~~
//!                   ~\ ~~/_  ~~~   /`-.--~~
//!                     `.  ---    .'   \_
//!                       `. " _.-'     | ~-.,-------._
//?                   ..._../~~   ./       .-'    .-~~~-.
//?             ,--~~~ ,'...\` _./.----~~.'/    /'       `-
//?         _.-(      |\    `/~ _____..-' /    /      _.-~~`.
//?        /   |     /. ^---~~~~       ' /    /     ,'  ~.   \
//?       (    /    (  .           _ ' /'    /    ,/      \   )
//?       (`. |     `\   - - - - ~   /'      (   /         .  |
//?        \.\|       \            /'        \  |`.           /
//?        /.'\\      `\         /'           ~-\         .  /\
//?       /,   (        `\     /'                `.___..-      \
//?     | |    \         `\_/'                  //      \.     |
//?     | |     |                              /' |       |     |

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
const int N = 2e6 + 5, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    map<int, int> hash;
    vl A;
    fo(i, 0, n)
    {
        cin >> k;
        if (hash[k] == 0)
        {
            A.pb(k);
            hash[k]++;
        }
    }
    sort(A.rbegin(), A.rend());
    n = A.size();
    ll t = 0;
    ll t2 = 0;
    fo(i, 0, n)
    {
        if (t >= A[i] - 1)
        {
            break;
        }

        for (j = i + 1; j < n; j++)
        {
            if (A[j] - 1 <= t)
            {
                break;
            }
            t2 = A[i] % A[j];
            if (t < t2)
            {
                t = t2;
            }
        }
    }
    cout << t << endl;
}

void solve2()
{

    int i, j, n, m, k;
    int temp = 0, flag = 1;
    cin >> n;
    vi A(N);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.begin() + n);
    //! Implementation
    int t2;
    fo(i, 0, n)
    {
        if (i && A[i] == A[i - 1]) // ! check for only unique elements
            continue;
        t2 = A[n - 1] / A[i];
        for (j = 2 * A[i]; j <= (t2 + 1) * A[i]; j += A[i])
        {
            // deb(j);
            int t = lower_bound(A.begin(), A.begin() + n, j) - A.begin();
            // cout << t - A.begin() << endl;
            // deb2(A[(t - 1)], j);
            if (t)
            {

                temp = max(A[t - 1] % A[i], temp);
            }
        }
    }
    cout << temp << endl;
}
int main()
{
    int t = 1;

    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================