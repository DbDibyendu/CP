#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1, sum = 0;
    cin >> n;
    vi A(n), prefix(n), suffix(n);

    fo(i, 0, n) cin >> A[i];
    int l = 0, r = n - 1;
    prefix[0] = A[0];
    suffix[n - 1] = A[n - 1];

    while (l < r)
    {
        if (l + 1 == r)
        {
            if (prefix[l] != suffix[r])
                temp++;

            break;
        }

        if (prefix[l] > suffix[r])
        {
            suffix[r - 1] = suffix[r] + A[r - 1];
            r--;
            temp++;
        }
        else if (prefix[l] < suffix[r])
        {
            prefix[l + 1] = prefix[l] + A[l + 1];
            l++;
            temp++;
        }
        else if (prefix[l] == suffix[r])
        {
            flag = prefix[l];

            for (j = l + 1; j < r; j++)
            {
                sum += A[j];
            }
            if (sum == flag)
            {
                temp += r - l - 2;
                cout << temp << endl;
                return;
            }
            else if (sum < flag)
            {
                prefix[l + 1] = prefix[l] + A[l + 1];
                l++;
                suffix[r - 1] = suffix[r] + A[r - 1];
                r--;
                temp += 2;
            }
            else if (sum > flag && sum % flag == 0)
            {
                if (prefix[l] != A[l + 1])
                    temp += 2;

                suffix[r - 1] = A[r - 1];
                r--;
                prefix[l + 1] = A[l + 1];
                l++;
            }
            else if (sum > flag && sum % flag != 0)
            {
                prefix[l + 1] = prefix[l] + A[l + 1];
                l++;
                suffix[r - 1] = suffix[r] + A[r - 1];
                r--;
                temp += 2;
            }
        }

        // deb2(l, r);
    }

    cout << temp << endl;
}

void solve2()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1, sum = 0;
    cin >> n;
    vi A(n), prefix(n, 0);

    fo(i, 0, n)
    {
        cin >> A[i];
        temp += A[i];
    }

    for (i = n; i > 0; i--)
    {
        flag = 0;
        int cursum = 0;
        if (temp % i == 0)
        {

            for (j = 0; j < n; j++)
            {
                cursum += A[j];

                if (cursum == temp / i)
                {
                    cursum = 0;
                    flag = 1;
                    continue;
                }
                else if (cursum > temp / i)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << n - i << endl;
            return;
        }
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