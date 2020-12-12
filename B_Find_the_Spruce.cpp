#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

int n, m;

void solve()
{

    int i, j, n, m, k, p, o;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    string tree[n];
    vvi arr;
    arr.assign(n, vector<int>(m, 0));

    k = m;
    fo(i, 0, n)
    {
        cin >> tree[i];
    }

    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            o = 0;
            for (k = 0; k < (m + 1) / 2; k++)
            {

                if (j - k >= 0 && j + k < m)
                {
                    if ((tree[i][j - k]) == '*' && (tree[i][j + k]) == '*')
                    {
                        o++;
                    }
                    else
                    {
                        break;
                    }
                }
                
            }
            arr[i][j] = o * 2 - 1;
        }
    }

    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
        //    deb(arr[i][j]);
            for (int k = 0; k < n - i; k++)
            {
                if (arr[k + i][j] >= 2 * (k + 1) - 1)
                {
                    temp++;
                }
                else
                {
                    break;
                }
            }
        }
    }

    cout << temp << endl;
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