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

bool check(int a, int b, int c, int d)
{

    float n = pow((a - c) ^ 2 + (d - b) ^ 2, 0.5);
    int res = n / 1;
    if (n <= 0 || n >= 0 && res * 1 == n)
    {
        return false;
    }
    else
        return true;
}

void solve()
{

    int i, j, n, m, k;
    int temp = 1, flag = 1;
    cin >> n >> m;

    if (n > m)
        swap(n, m);
    k = n + 1;
    if (k == 2)
    {
        cout << k << endl;
        cout << 0 << " " << 1 << endl;
        cout << 1 << " " << 0 << endl;
    }
    else
    {
        cout << k << endl;
      
        fo(i, 0, k)
        {
            cout<<i<<" "<<k-1-i<<endl;
            
        }
    }
}

int main()
{
    int t = 1;
    while (t--) 
    {
        solve();
    }
    return 0;
}

//=======================