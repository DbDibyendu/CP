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
    ll temp = 0, flag = 1, valA = 0, valB = 0;
    cin >> n;
    string A, B;

    cin >> A >> B;

    fo(i, 0, n)
    {
        if (A[i] - '0' > B[i] - '0')
            valA ++;

        else if (B[i] - '0' > A[i] - '0')
            valB ++; 
    }
    if (valA > valB)
        cout << "RED" << endl;
    else if (valB > valA)
        cout << "BLUE" << endl;
    else
        cout << "EQUAL" << endl;

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