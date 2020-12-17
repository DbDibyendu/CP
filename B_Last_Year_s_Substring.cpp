#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    string A;
    cin >> A;

    if (A[0] == '2' && A[1] == '0' && A[n - 2] == '2' && A[n - 1] == '0')
    {
        cout << "YES" << endl;
        return;
    }
    else if (A[0] == '2' && A[n-3] == '0' && A[n - 2] == '2' && A[n - 1] == '0')
    {
        cout << "YES" << endl;
        return;
    }
    else if (A[n-4] == '2' && A[n-3] == '0' && A[n - 2] == '2' && A[n - 1] == '0')
    {
        cout << "YES" << endl;
        return;
    }
    else if (A[0] == '2' && A[1] == '0' && A[2] == '2' && A[n - 1] == '0')
    {
        cout << "YES" << endl;
        return;
    }
    else if (A[0] == '2' && A[1] == '0' && A[2] == '2' && A[3] == '0')
    {
        cout << "YES" << endl;
        return;
    }
    /*
    for (i = 0; i < n - 4; i++)
    {
        if (A[i] == '2' && A[i + 1] == '0' && A[i + 2] == '2' && A[i + 3] == '0')
        {
            cout << "YES" << endl;
            return;
        }
    }
    */
    cout<<"NO"<<endl;

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