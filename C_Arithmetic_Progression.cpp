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

// All about checking cases
void solve()
{

    ll i, j, n, m, k, t1, t2;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    vl D(n, 0);
    map<ll, ll> unique;
    fo(i, 0, n)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    fo(i, 0, n)
    {
        if (i >= 1)
        {
            D[i] = A[i] - A[i - 1];
            unique[D[i]]++;
        }
    }

    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }

    if (unique.size() == 1)
    {
        if (D[1] == 0)
        {
            cout << 1 << endl;
            cout << A[0] << endl;
        }
        else if (n == 2)
        {
            if (D[1] % 2 == 0)
            {
                cout << 3 << endl;
                cout << A[0] - D[1] << " " << (A[0] + A[n - 1]) / 2 << " " << A[n - 1] + D[1] << endl;
            }
            else
            {
                cout << 2 << endl;
                cout << A[0] - D[1] << " " << A[n - 1] + D[1] << endl;
            }
        }

        else
        {
            cout << 2 << endl;
            cout << A[0] - D[1] << " " << A[n - 1] + D[1] << endl;
        }
    }

    else if (unique.size() == 2)
    {
        auto it = unique.end();
        it--;
        t2 = it->first;
        it--;
        t1 = it->first;
        //       deb2(t2, unique[t2]);
        
        if (t1 != 0 && t2 / 2 == t1 && unique[t2] == 1)
        {
            cout << 1 << endl;

            for (i = 1; i < n; i++)
            {
                if (D[i] == t2)
                {
                    cout << A[i - 1] + t1 << endl;
                    break;
                }
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << 0 << endl;
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