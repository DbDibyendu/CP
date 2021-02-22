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

char A[1005];
ll Num[1005];

// ! Attempt 1, Passed 20 test cases
void solve()
{

    int p, i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> p;
    m = n;
    fo(i, 0, n)
    {
        cin >> A[i];
        Num[i] = A[i] - 'a';
    }
    if (n == 1)
    {
        if (p == 1)
        {
            cout << "NO";
            return;
        }
        else
        {
            if (Num[0] == p - 1)
            {
                cout << "NO";
                return;
            }
            cout << char(Num[0] + 1 + 'a');
            return;
        }
    }
    else if (n == 2)
    {
        if (p < 2)
        {
            cout << "NO";
            return;
        }
        for (i = 0; i < n; i++)
        {
            if (Num[i] == p - 1)
            {
                continue;
            }
            else
            {
                for (j = 1; j <= p - Num[i] - 1; j++)
                {
                    if (i == 1)
                    {
                        if (Num[i] + j != Num[i - 1])
                        {
                            Num[i] += j;
                            k = i;
                            flag = 0;
                            break;
                        }
                    }
                    else
                    {
                        Num[i] += j;
                        k = i;
                        flag = 0;
                        break;
                    }
                }

                j = 0;
                if (flag == 0)
                    for (i = k + 1; i < n; i++)
                    {
                        Num[i] = j % p;
                        j++;
                    }
                if (flag == 0)
                    break;
            }
        }
        if (flag)
        {
            cout << "NO";
            return;
        }
    }
    if (n > 2)
    {
        if (p < 3)
        {

            cout << "NO";
            return;
        }
        for (i = n - 1; i >= 0; i--)
        {
            if (Num[i] == p - 1)
            {
                continue;
            }
            else
            {
                if (i - 2 >= 0)
                {
                    // deb2(i, Num[i]);
                    for (j = 1; j <= p - Num[i] - 1; j++)
                    {
                        // deb(Num[i] + j);
                        if (Num[i] + j != Num[i - 1] && Num[i] + j != Num[i - 2])
                        {
                            Num[i] += j;
                            k = i;
                            flag = 0;
                            break;
                        }
                    }
                }
                else
                {
                    for (j = 1; j <= p - Num[i] - 1; j++)
                    {
                        // deb(Num[i] + j);
                        if (i == 1)
                        {
                            if (Num[i] + j != Num[i - 1])
                            {
                                Num[i] += j;
                                k = i;
                                flag = 0;
                                break;
                            }
                        }
                        else
                        {
                            Num[i] += j;
                            k = i;
                            flag = 0;
                            break;
                        }
                    }
                }

                j = 0;
                if (flag == 0)
                    for (i = k + 1; i < n; i++)
                    {
                        Num[i] = j % p;
                        j++;
                    }
            }
            if (flag == 0)
                break;
        }
        if (flag)
        {
            cout << "NO";
            return;
        }
    }

    fo(i, 0, m)
    {
        cout << char(Num[i] + 'a');
    }
}

void solve2()
{
    int p, i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> p;
    m = n;
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    i = n - 1;
    A[n - 1]++;
    while (i >= 0 && i < n)
    {
        if (A[i] - 'a' >= p)
        {
            A[i] = 'a';
            A[i - 1]++;
            i--;
        }
        else if (A[i] == A[i - 1] || A[i] == A[i - 2])
        {
            A[i]++;
        }
        else
        {
            i++;
        }
    }
    if (i < 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << A << endl;
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================