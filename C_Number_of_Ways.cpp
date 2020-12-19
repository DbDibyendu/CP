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
    ll sum = 0, temp = 0, count = 0;
    ll b1 = 0, b2 = 0;
    cin >> n;
    if (n < 3)
    {
        cout << 0 << endl;
        return;
    }
    vi A(n), prefix(n, 0);

    fo(i, 0, n)
    {
        cin >> A[i];
        sum += A[i];
        if (i == 0)
            prefix[i] = A[i];
        else
            prefix[i] += A[i] + prefix[i - 1];
    }
    if (sum % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }
    k = sum / 3;
    for (i = 0; i < n - 1; i++)
    {


        // for number of 2nd boundary... multiplying them with number of possible 1st boundary
        if (prefix[i] == 2 * k)
        {
            temp += count;
        }
        // first boundary
        if (prefix[i] == k)
        {
            count++;
        }
    }
    cout << temp << endl;
}

int main()
{
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================