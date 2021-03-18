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

// ! Substr( position, length);

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A, B;
    cin >> A;
    n = A.length();
    ll G[26] = {0};
    clr(G);
    cin >> B;
    cin >> k;
    fo(i, 0, 26)
    {
        m = (int)B[i] - '0';
        G[i] = m > 0 ? 0 : 1;
    }

    map<string, int> hash;
    map<char, int> T;

    for (i = 0; i < n; i++)
    {
        if (k > 0)
        {
            if (T[A[i]] == 0)
            {
                T[A[i]]++;
                temp++;
            }
        }
        else
        {
            if (G[A[i] - 'a'] == 0)
            {
                if (T[A[i]] == 0)
                {
                    T[A[i]]++;
                    temp++;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        flag = G[A[i] - 'a'];
        for (j = i + 1; j < n; j++)
        {
            if (hash[A.substr(i, j - i + 1)] == 0)
            {
                hash[A.substr(i, j - i + 1)]++;
                // deb(A.substr(i, j - i + 1));
                flag += G[A[j] - 'a'];
                // deb(flag);
                if (flag <= k)
                {
                    temp++;
                    // deb(temp);
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag += G[A[j] - 'a'];
            }
        }
        // deb(temp);
    }
    cout << temp;
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