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

// ! attempt1, Very long solution and wrong approach
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1, pA = 0, nA = 0;
    cin >> n >> m;
    vl A(n), B(m);
    fo(i, 0, n)
    {
        cin >> A[i];
        if (A[i] > 0)
        {
            pA++;
        }
        else
        {
            nA++;
        }
    }
    map<ll, ll> hash;
    ll p2 = 0, n2 = 0;
    fo(i, 0, m)
    {
        cin >> B[i];
        hash[B[i]]++;
        if (B[i] > 0)
        {
            p2 = B[i];
        }
    }
    if (B[0] < 0)
    {
        n2 = B[0];
    }

    ll p1 = 0, n1 = 0, temp2 = 0, prevtemp2 = 0;
    ll prevtemp = 0;

    fo(i, 1, m)
    {

        if (B[i] > 0)
        {
            if (B[i] == B[i - 1] + 1)
            {
                temp++;
            }
            else
            {

                if (temp > prevtemp)
                {
                    p1 = B[i - 1];
                    prevtemp = temp;
                }
                else
                {
                }
                temp = 0;
            }
            p2 = B[i];
        }
        else
        {
            if (B[i] == B[i - 1] + 1)
            {
                temp2++;
            }
            else
            {

                if (temp2 > prevtemp2)
                {
                    n1 = B[i - temp2];
                    prevtemp2 = temp2;
                    // deb(prevtemp2);
                }
                else
                {
                }

                temp2 = 0;
            }
            n2 = B[0];
            j = i;
        }
    }
    if (temp > prevtemp)
    {
        prevtemp = temp;
        p1 = B[m - 1];
    }
    if (temp2 > prevtemp2)
    {
        n1 = B[j - temp2];
        prevtemp2 = temp2;
    }
    prevtemp++, prevtemp2++;
    // deb2(p2, prevtemp);
    ll ans = 0, ansP = 0;
    if (pA >= prevtemp)
    {
        if (prevtemp > 1)
        {
            fo(i, 0, n)
            {
                if (A[i] > 0)
                {
                    if (A[i] > p1)
                    {
                        if (hash[A[i]])
                        {
                            ans++;
                        }
                    }
                    if (A[i] <= p1)
                    {
                        ansP++;
                        if (ansP >= prevtemp)
                        {
                            ansP = prevtemp;
                        }
                    }
                }
            }
            ans += ansP;
        }
        else
        {
            fo(i, 0, n)
            {
                if (A[i] > 0)
                    if (A[i] <= p2)
                    {
                        ans++;
                        break;
                    }
            }
            // deb2(ans, p2);
        }
    }
    else
    {
        fo(i, 0, n)
        {
            if (A[i] > 0)
                if (A[i] <= p1)
                {
                    ans++;
                }
        }
    }
    ll ansN = 0;
    if (prevtemp2 <= nA)
    {

        if (prevtemp2 > 1)
        {
            fo(i, 0, n)
            {
                if (A[i] < 0)
                {
                    if (A[i] < n1)
                    {
                        if (hash[A[i]])
                        {
                            ans++;
                        }
                    }
                    else if (A[i] >= n1)
                    {
                        ansN++;
                        if (ansN >= prevtemp2)
                        {
                            ansN = prevtemp2;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            ans += ansN;
        }
        else
        {
            fo(i, 0, n)
            {
                if (A[i] < 0)
                    if (A[i] >= n2)
                    {
                        ans++;
                        break;
                    }
            }
        }
    }
    else
    {
        fo(i, 0, n)
        {
            if (A[i] < 0)
                if (A[i] >= n1)
                {
                    ans++;
                }
        }
    }

    cout << ans << endl;
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