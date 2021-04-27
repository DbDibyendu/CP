#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
int main()
{
    fast;
    ll t = 1;
    std::cin >> t;
    while (t--)
    {
        ll a, b, i, j = 0;
        std::cin >> a >> b;
        string s;
        cin >> s;
        ll n = a + b;
        swap(a, b);
        fr(i, 0, n / 2)
        {
            if (s[i] == '1')
            {
                a--;
                if (s[n - i - 1] == '?')
                {
                    s[n - i - 1] = '1';
                    a--;
                }
                else if (s[n - i - 1] == '1')
                {
                    a--;
                }
                else
                {
                    j = 1;
                    break;
                }
            }
            if (s[i] == '0')
            {
                b--;
                if (s[n - i - 1] == '?')
                {
                    s[n - i - 1] = '0';
                    b--;
                }
                else if (s[n - i - 1] == '0')
                {
                    b--;
                }
                else
                {
                    j = 1;
                    break;
                }
            }
            if (s[i] == '?')
            {
                if (s[n - i - 1] == '?')
                {
                    continue;
                }
                s[i] = s[n - i - 1];
                if (s[n - i - 1] == '0')
                {
                    b--;
                    b--;
                }
                else
                {
                    a--;
                    a--;
                }
            }
            // cout << b << "\n";
        }
        if (n % 2 != 0)
        {
            if (s[n / 2] == '1')
                a--;
            else if (s[n / 2] == '0')
                b--;
            else
            {
                if (a % 2 != 0)
                {
                    a--;
                    s[n / 2] = '1';
                }
                else if (b % 2 != 0)
                {
                    b--;
                    s[n / 2] = '0';
                }
                else
                {
                    a--;
                    s[n / 2] = '1';
                }
            }
        }
        // cout << a << " " << b << "\n";
        if (j == 1 || a < 0 || b < 0)
        {
            cout << "-1\n";
            continue;
        }
        if (a % 2 != 0 || b % 2 != 0)
        {
            cout << "-1\n";
            continue;
        }
        fr(i, 0, n / 2)
        {
            if (s[i] == '?')
            {
                if (s[n - i - 1] == '?')
                {
                    if (a > b)
                    {
                        s[i] = s[n - i - 1] = '1';
                        a--;
                        a--;
                    }
                    else
                    {
                        s[i] = s[n - i - 1] = '0';
                        b--;
                        b--;
                    }
                }
            }
        }
        cout << s << "\n";
    }
}