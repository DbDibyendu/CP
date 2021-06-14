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
const int N = 2e5 + 10, M = N;
//=======================

//! Failed attempt, almost the logic failed.... I had to check overall occuring of an element in positiion i and k-i-1
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> n >> k;
    cin >> A;
    ll cnt[27];
    ll cnt2[27];
    clr(cnt);
    if (k == 1 || k == 2)
    {
        fo(i, 0, n)
        {
            cnt[(int)A[i] - 'a']++;
        }
        fo(i, 0, 26)
        {
            temp = max(temp, cnt[i]);
        }
        cout << n - temp << endl;
        return;
    }
    if (k & 1)
    {

        ll final[k];
        clr(final);

        for (i = 0; i < (k + 1) / 2; i++)
        {
            clr(cnt);
            for (j = i; j < n; j += k)
            {
                cnt[(int)A[j] - 'a']++;
            }
            ll t = 0, letter = 0;
            ll j2;
            fo(j2, 0, 26)
            {
                if (cnt[j2] >= t)
                {
                    letter = j2;
                    t = cnt[j2];
                }
            }
            clr(cnt2);
            for (j = k - i - 1; j < n; j += k)
            {
                cnt2[(int)A[j] - 'a']++;
            }
            ll t2 = 0, letter2 = 0;
            fo(j2, 0, 27)
            {
                if (cnt[j2] >= t2)
                {
                    letter2 = j2;
                    t2 = cnt[j2];
                }
            }
            // deb2(letter, letter2);
            // clr(cnt);
            if (t > t2)
            {
                final[i] = letter;
            }
            else
            {
                final[i] = letter2;
            }
        }
        for (i = 0; i < (k + 1) / 2; i++)
        {
            final[k - i - 1] = final[i];
        }
        // display(final);

        temp = 0;

        for (i = 0; i < n; i += k)
        {
            for (j = 0; j < k; j++)
            {

                if ((int)A[i + j] - 'a' != final[j])
                {
                    temp++;
                }
                else
                {
                    // deb2(A[i + j] - 'a', final[j]);
                    // deb(i + j);
                }
            }
        }
        cout << temp << endl;
    }
    else
    {

        ll final[k];
        clr(final);
        // ll first_sum = 0;

        for (i = 0; i < k / 2; i++)
        {
            clr(cnt);
            for (j = i; j < n; j += k)
            {
                cnt[(int)A[j] - 'a']++;
            }
            ll t = 0, letter = 0;
            ll j2;
            fo(j2, 0, 27)
            {
                if (cnt[j2] >= t)
                {
                    letter = j2;
                    t = cnt[j2];
                }
            }
            clr(cnt);
            for (j = k - i - 1; j < n; j += k)
            {
                cnt[(int)A[j] - 'a']++;
            }
            ll t2 = 0, letter2 = 0;
            fo(j2, 0, 27)
            {
                if (cnt[j2] >= t2)
                {
                    letter2 = j2;
                    t2 = cnt[j2];
                }
            }

            if (t > t2)
            {
                final[i] = letter;
            }
            else
            {
                final[i] = letter2;
            }
        }
        for (i = 0; i < k / 2; i++)
        {
            final[k - i - 1] = final[i];
        }
        // display(final);
        for (i = 0; i < n; i += k)
        {
            for (j = 0; j < k; j++)
            {
                if ((int)A[i + j] - 'a' != final[j])
                {
                    temp++;
                }
            }
        }
        cout << temp << endl;
    }
}

int n, k, ans = 0;
int cnt[N][26];
string s;

//! Effective Imlementation
int differ(int u, int v)
{
    int ret = 0, mx = 0;
    for (int j = 0; j < 26; ++j)
    {
        ret += cnt[u][j] + cnt[v][j];
        mx = max(mx, cnt[u][j] + cnt[v][j]); //! Calculating the max occuring element
    }
    return ret - mx; //! Returning all extras
}

int solve2()
{

    cin >> n >> k >> s;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            cnt[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cnt[i % k][s[i] - 'a']++;
    }
    int ans = 0;
    if (k % 2 == 0)
        for (int i = 0; i < k / 2; ++i)
        {
            ans += differ(i, k - 1 - i);
        }
    else
    {
        for (int i = 0; i < k / 2; ++i)
        {
            ans += differ(i, k - 1 - i);
        }
        int ret = 0, mx = 0;
        for (int j = 0; j < 26; ++j)
        {
            ret += cnt[k / 2][j];
            mx = max(mx, cnt[k / 2][j]); //! Calculating the max occuring element
        }
        ans += ret - mx;
    }
    cout << ans << "\n";

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================