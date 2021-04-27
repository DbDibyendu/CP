//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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
bool isPerfectSquare(int x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0)
    {

        int sr = sqrt(x);

        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i, 0, n)
    {
        for (j = i + 1; j < n; j++)
        {
            if (isPerfectSquare(A[i] * A[j]))
            {
                continue;
            }
            else
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    // precalc();
    ll tt, i, n;
    cin >> tt;
    bool sq[10002];
    memset(sq, false, sizeof(sq));

    for (int i = 1; i < 101; i++)
        sq[i * i] = true;

    while (tt--)
    {
        cin >> n;
        bool ok = false;
        vl v1(n);
        fo(i, 0, n)
        {
            cin >> v1[i];
        }

        fo(i, 0, n) if (!sq[v1[i]])
            ok = true;

        cout << ((ok) ? "YES\n" : "NO\n");
    }
    return 0;
}

//=======================