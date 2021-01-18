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
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

// Long approach written by me

void solve()
{

    int i, j, n, m, k = 0, n1, n2, p;
    ll temp = 0, flag = 1, pattern = 1, l = 0;
    string s, t;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    char rep[20];

    if (n < m)
    {
        rep[0] = s[0];
        n1 = 0;
        k = 1;
        for (i = 1; i < n; i++)
        {
            n1 = 1;
            for (p = i; p < n; p += k)
            {
                for (j = 0; j < k; j++)
                {
                    if (rep[j] == s[p + j])
                    {
                        pattern = 1;
                        continue;
                    }
                    else
                    {
                        pattern = 0;
                        break;
                    }
                }
                n1++;
                if (pattern == 0)
                {
                    break;
                }
            }
            if (pattern == 1)
            {
                break;
            }
            rep[i] = s[i];
            k++;
        }

        if (k == n)
        {
            n1 = 1;
        }
        n2 = 0;
        for (i = 0; i < m; i += k)
        {
            for (j = 0; j < k; j++)
            {
                if (rep[j] == t[i + j])
                {
                    flag = 1;
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << -1 << endl;
                return;
            }
            n2++;
        }
        temp = lcm(n1, n2);
        for (i = 0; i < temp; i++)
        {
            for (j = 0; j < k; j++)
            {
                cout << rep[j];
            }
        }
        cout << endl;
    }

    else
    {
        rep[0] = t[0];
        n1 = 0;
        k = 1;
        for (i = 1; i < m; i++)
        {
            n1 = 1;
            for (p = i; p < m; p += k)
            {
                for (j = 0; j < k; j++)
                {
                    if (rep[j] == t[p + j])
                    {
                        pattern = 1;
                        continue;
                    }
                    else
                    {
                        pattern = 0;
                        break;
                    }
                }
                n1++;
                if (pattern == 0)
                {
                    break;
                }
            }
            if (pattern == 1)
            {
                break;
            }
            rep[i] = t[i];
            k++;
        }

        if (k == m)
        {
            n1 = 1;
        }
        n2 = 0;
        for (i = 0; i < n; i += k)
        {
            for (j = 0; j < k; j++)
            {
                if (rep[j] == s[i + j])
                {
                    flag = 1;
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << -1 << endl;
                return;
            }
            n2++;
        }
        temp = lcm(n1, n2);

        for (i = 0; i < temp; i++)
        {
            for (j = 0; j < k; j++)
            {
                cout << rep[j];
            }
        }
        cout << endl;
    }
}

// Short approach
void solve2()
{
    int i, j, n, m, count = 0;
    ll temp = 0, flag = 1;
    string s, t;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    vector<char> s1, s2;
    temp = lcm(n, m);
    for (i = 0; i < temp; i++)
    {
        s1.push_back(s[i % n]);
        s2.push_back(t[i % m]);
    }
    for (i = 0; i < temp; i++)
    {
        if (s1[i] == s2[i])
            count++;
    }
    if (count == temp)
    {
        for (i = 0; i < temp; i++)
            cout << s1[i];

        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================