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
const int N = 1005, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    ll r, c;
    cin >> r >> c;
    ll A[N][N];
    clr(A);
    fo(i, 0, r)
    {
        fo(j, 0, c)
        {
            cin >> A[i][j];
        }
    }

    int RowU[r + 1][c + 1] = {}, RowD[r + 1][c + 1], ColR[r + 1][c + 1], ColL[r + 1][c + 1];
    clr(RowU), clr(RowD), clr(ColR), clr(ColL);
    fo(i, 0, r)
    {
        fo(j, 0, c)
        {
            if (j == 0)
                ColL[i][j] = A[i][j];
            else
            {
                if (A[i][j])
                    ColL[i][j] = A[i][j] + ColL[i][j - 1];
                else
                {
                    ColL[i][j] = 0;
                }
            }
        }
    }

    fo(i, 0, r)
    {
        for (j = c - 1; j >= 0; j--)
        {
            if (j == c - 1)
                ColR[i][j] = A[i][j];
            else
            {
                if (A[i][j])
                    ColR[i][j] = A[i][j] + ColR[i][j + 1];
                else
                {
                    ColR[i][j] = 0;
                }
            }
        }
    }

    fo(j, 0, c)
    {
        fo(i, 0, r)
        {
            if (i == 0)
                RowU[i][j] = A[i][j];
            else
            {
                if (A[i][j])
                    RowU[i][j] = A[i][j] + RowU[i - 1][j];
                else
                {
                    RowU[i][j] = 0;
                }
            }
        }
    }

    fo(j, 0, c)
    {
        for (i = r - 1; i >= 0; i--)
        {
            if (i == r - 1)
                RowD[i][j] = A[i][j];
            else
            {
                if (A[i][j])
                    RowD[i][j] = A[i][j] + RowD[i + 1][j];
                else
                {
                    RowD[i][j] = 0;
                }
            }
        }
    }
    int t, t2;
    fo(i, 0, r)
    {
        fo(j, 0, c)
        {
            // deb2(ColL[i][j], ColR[i][j]);
            // deb2(RowU[i][j], RowD[i][j]);

            //! Vice versa

            if (ColL[i][j] > 1)
            {
                t = RowD[i][j] / 2;
                t2 = RowU[i][j] / 2;
                if (min(ColL[i][j], t) > 1)
                    temp += min(ColL[i][j], t) - 1;
                if (min(ColL[i][j], t2) > 1)
                    temp += min(ColL[i][j], t2) - 1;
            }
            if (ColR[i][j] > 1)
            {
                t = RowD[i][j] / 2;
                t2 = RowU[i][j] / 2;
                if (min(ColR[i][j], t) > 1)
                    temp += min(ColR[i][j], t) - 1;
                if (min(ColR[i][j], t2) > 1)
                    temp += min(ColR[i][j], t2) - 1;
            }

            if (RowU[i][j] > 1)
            {
                t = ColL[i][j] / 2;
                t2 = ColR[i][j] / 2;
                if (min(RowU[i][j], t) > 1)
                    temp += min(RowU[i][j], t) - 1;
                if (min(RowU[i][j], t2) > 1)
                    temp += min(RowU[i][j], t2) - 1;
            }
            if (RowD[i][j] > 1)
            {
                t = ColL[i][j] / 2;
                t2 = ColR[i][j] / 2;
                if (min(RowD[i][j], t) > 1)
                    temp += min(RowD[i][j], t) - 1;
                if (min(RowD[i][j], t2) > 1)
                    temp += min(RowD[i][j], t2) - 1;
            }
            // deb(temp);
        }
       
        // deb(temp);
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