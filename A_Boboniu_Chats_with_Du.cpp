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

//! Fucked up 2 pointers approach
void solve()
{

    ll i, j, n, m, k, d;
    ll temp = 0, flag = 1;
    cin >> n >> d >> m;
    vl A(n, 0);
    read(A);
    sort(A.begin(), A.end());
    vl B;
    k = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (A[i] > m)
        {
            B.push_back(A[i]);
            A.pop_back();
            // temp += A[i];
            k++;
        }
        else
        {
            break;
        }
    }
    ll b = B.size();
    sort(A.begin(), A.end());
    vl C;
    k = 0;
    ll t = 0;
    ll sum = 0;
    display(A);
    display(B);
    for (j = b - 1; j >= 0; j--)
    {

        sum = 0;

        for (i = k; i < min(d + k, n); i++)
        {
            sum += A[i];
            // k++;
        }
        k = i;

        if (sum >= B[j])
        {
            C.push_back(B[j]); //! Not taking this element
            temp += sum;
        }
        else
        {
            temp += B[j];
        }
        if (i == n - 1)
        {
            break;
        }
        deb(temp);
    }
    deb2(temp, j);
    for (i = j; i >= 0; i--)
    {
        C.push_back(B[i]);
    }
    sort(C.rbegin(), C.rend());
    for (i = 0; i < C.size(); i++)
    {
        if (i % (d + 1) == 0)
            temp += C[i];
    }
    cout << temp << endl;
    // display(A);
}

//! Tough logic, implementation is quite easy
void solve2()
{
    ll i, j, n, m, k, d;
    ll temp = 0, flag = 1;
    cin >> n >> d >> m;
    vl A(n + 1);
    k = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (A[i] > m)
        {
            k++;
        }
    }
    sort(A.begin() + 1, A.end());
    reverse(A.begin() + 1, A.end());
    for (i = 2; i <= n; i++)
    {
        A[i] += A[i - 1];
    }
    if (k == 0)
    {
        cout << A[n] << endl;
        return;
    }
    // display(A);
    for (i = 1; i <= n; i++)
    {
        ll d_left = n - ((i - 1) * (d + 1) + 1);
        //! Taking the biggest element from days left
        if (d_left >= 0)
            temp = max(temp, A[i] + A[min(k + d_left, n)] - A[k]);
        // deb(temp);
    }

    cout << temp << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================