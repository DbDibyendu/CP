#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A, B;
    cin >> A >> B;
    n = A.size();
    m = B.size();
    map<char, int> hash1;
    for (i = 0; i < n; i++)
    {
        hash1[A[i]]++;
    }
    fo(i, 0, m)
    {
        if (hash1[B[i]])
        {
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<vector<int>> pos(n + 5, vector<int>(26, MOD));
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < 26; j++)
        {
            pos[i][j] = pos[i + 1][j];
        }
        pos[i][A[i] - 'a'] = i;
    }

    temp = 1;
    j = 0;
    for (i = 0; i < m; i++)
    {
        if (pos[j][B[i] - 'a'] >= MOD)
        {
            temp++;
            j = 0;
        }
        j = pos[j][B[i] - 'a'] + 1;
    }
    cout << temp << endl;
}

void solve2()
{
    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    vector<bool> present(26, false);

    for (int i = 0; i < len2; i++)
    {
        present[s2[i] - 'a'] = true;
    }

    for (int i = 0; i < len1; i++)
    {
        present[s1[i] - 'a'] = false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (present[i])
        {
            cout << "-1\n";
            return;
        }
    }

    vector<vector<int>> pos(len1 + 5, vector<int>(26, MOD));
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            pos[i][j] = pos[i + 1][j];
        }
        pos[i][s1[i] - 'a'] = i;
    }

    int count = 1;

    int j = 0;
    for (int i = 0; i < len2; i++)
    {
        if (pos[j][s2[i] - 'a'] >= MOD)
        {
            count++;
            j = 0;
        }

        j = pos[j][s2[i] - 'a'] + 1;
    }

    cout << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================