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
const int N = 305, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    vl A(n, 0);
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (n == 2)
    {
        if (A[1] <= A[0])
        {
            ll t = A[0];
            int ten = 0;
            while (t)
            {
                t /= 10;
                ten++;
            }
            ll t2 = A[1];
            int ten2 = 0;
            while (t2)
            {
                t2 /= 10;
                ten2++;
            }

            temp += ten - ten2 + 1;
        }
    }
    if (n == 3)
    {
        if (A[1] <= A[0])
        {
            ll t = A[0];
            int ten = 0;
            while (t)
            {
                t /= 10;
                ten++;
            }
            ll t2 = A[1];
            int ten2 = 0;
            while (t2)
            {
                t2 /= 10;
                ten2++;
            }
            // deb2(ten, ten2);
            temp += ten - ten2 + 1;
            A[1] *= pow(10, temp);
            // deb(A[1]);
        }
        if (A[2] == A[1])
        {
            temp++;
        }
        if (A[2] < A[1])
        {
            ll t = A[1];
            int ten = 0;
            while (t)
            {
                t /= 10;
                ten++;
            }
            ll t2 = A[2];
            int ten2 = 0;
            while (t2)
            {
                t2 /= 10;
                ten2++;
            }
            // deb2(ten, ten2);
            temp += ten - ten2 + 1;
            A[2] *= pow(10, ten - ten2 + 1);
            if (A[2] / 10 == A[1])
            {
                temp--;
            }
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