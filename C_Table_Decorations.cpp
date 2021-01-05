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
typedef vector<ll> vl;
//=======================

// Approach 1 ( wrong appraoch)
void solve()
{

    ll i, j, n, smallest, k, r, g, b;
    ll table_max = 0, ans = 0;
    vi A(3, 0);
    cin >> A[0] >> A[1] >> A[2];

    sort(A.begin(), A.end());

    if (A[0] > 0)
    {
        ans = A[0];
        A[1] = A[1] - ans;
        A[2] = A[2] - ans;

        if (A[1] > 0)
        {
            if (A[2] / 2 >= A[1])
            {
                ans += A[1];
            }
            else
            {

                ans += A[2] / 2;
                A[1] = A[1] - A[2] / 2;
                if (A[2] % 2 == 1 && A[1] >= 2)
                {
                    ans++;
                }
            }
        }
    }
    else
    {

        if (A[1] > 0)
        {
            if (A[2] / 2 >= A[1])
            {
                ans += A[1];
            }
            else
            {

                ans += A[2] / 2;
                A[1] = A[1] - A[2] / 2;
                if (A[2] % 2 == 1 && A[1] >= 2)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

void solve1()
{
    ll i, j, n, k, r, g, b;
    ll table_max = 0, ans = 0;
    vl A(3, 0);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());

    if(A[2]>= 2*(A[1]+A[0])){
        cout<<(A[0]+A[1])<<endl;
    }
    else{
        cout<<(A[0]+A[1]+A[2])/3<<endl;
    }
}
int main()
{
    int t = 1;

    while (t--)
    {
        solve1();
    }
    return 0;
}

//=======================