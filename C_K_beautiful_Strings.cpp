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

//! Good question, implemented on my own 
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    string A;
    cin >> A;
    if (n % k)
    {
        cout << -1 << endl;
        return;
    }

    flag = 1;
    vl count(26, 0);
    fo(i, 0, n)
    {
        count[A[i] - 'a']++;
    }
    fo(i, 0, 26)
    {
        if (count[i] % k != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << A << endl;
        return;
    }

    vl ans;
    bool found = 0;
    ll sum = 0, rem, t1, el;
    for (i = n - 1; i >= 0; i--)
    {
        count[A[i] - 'a']--;
        rem = n - i - 1;
        sum = 0;
        fo(j, 0, 26)
        {
            if (count[j])
            {
                if (count[j] % k != 0)
                    sum += k - (count[j] % k);
            }
        }
        fo(j, 0, 26)
        {
            if (j > A[i] - 'a')
            {
                // ! Resetting sum WITH the current charc
                if (count[j] % k != 0)
                    sum -= k - (count[j] % k);
                count[j]++;
                if (count[j] % k != 0)
                    sum += k - (count[j] % k);
                // deb(sum);
                if (sum <= rem)
                {
                    found = 1;
                    t1 = i;
                    el = j;
                    break;
                }
                else
                {
                    // ! Resetting sum WITHOUT the current charc
                    if (count[j] % k != 0)
                        sum -= k - (count[j] % k);
                    count[j]--;
                    if (count[j] % k != 0)
                        sum += k - (count[j] % k);
                }
            }
        }
        if (found == 1)
        {
            break;
        }
    }
    // deb2(sum, rem);
    // ! Printing the previous string
    fo(i, 0, t1)
    {
        cout << A[i];
    }
    cout << (char)(el + 'a');

    // ! First print all the A's in here
    for (i = 0; i < rem - sum; i++)
    {
        cout << 'a';
    }

    fo(i, 0, 26)
    {
        if (count[i])
        {
            if (count[i] % k)
            {
                temp = k - count[i] % k;
                fo(j, 0, temp)
                {
                    cout << (char)(i + 'a');
                    // deb(j);
                }
            }
        }
    }
    cout << endl;
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