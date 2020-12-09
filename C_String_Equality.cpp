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
    string a, b;
    cin >> n >> k;
    cin >> a >> b;
    vector<int> A(n, 0), B(n, 0);
    vector<int> dpa(26, 0), dpb(26, 0);

    fo(i, 0, n)
    {

        dpa[int(a[i] - 'a')] += 1;
        dpb[int(b[i] - 'a')] += 1;
    }

    cout << endl;
    fo(i, 0, 26)
    {
        
        if (dpb[i] > dpa[i] || (dpa[i] = dpa[i] - dpb[i]) % k)  // First condition one is checked first , if not satisfied then 2nd
        {
            cout << "No";
            return;
        }

        

        // Alternative solution.....pls check to understand
        /*
        if (dpb[i] > dpa[i] || (dpa[i]-dpb[i]) % k)  
        {
            cout << "No";
            return;
        }
        if(dpa[i]>=dpb[i]) dpa[i]=dpa[i]-dpb[i];
        */


        dpa[i + 1] += dpa[i];
    }
    cout << "Yes";
    return;
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