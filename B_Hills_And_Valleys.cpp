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
const int N = 4*100000, M = N;
//=======================

int A[N], n;

int isHillVal(int i)
{
    if (i > 0 && i < n - 1 && A[i - 1] < A[i] && A[i] > A[i + 1])
    {
        return 1;
    }
    else if (i > 0 && i < n - 1 && A[i - 1] > A[i] && A[i] < A[i + 1])
    {
        return 1;
    }
    return 0;
}

void solve()
{

    ll i, j, m, k;
    ll sum = 0, flag = 0, temp = 0;
    cin >> n;

    int valHill[n]={0};

    fo(i, 0, n) cin >> A[i];

    for (i = 1; i < n - 1; i++)
    {
        // hills
        if (isHillVal(i))
        {
            valHill[i] = 1;
            sum++;
        }
    }

    temp = sum;

    for (i = 1; i < n - 1; i++)
    {
        flag = A[i];
        A[i] = A[i - 1];
        sum = min(sum, temp - valHill[i] - valHill[i - 1] - valHill[i + 1] + isHillVal(i) + isHillVal(i - 1) + isHillVal(i + 1));
        A[i] = A[i + 1];
        sum = min(sum, temp - valHill[i] - valHill[i - 1] - valHill[i + 1] + isHillVal(i) + isHillVal(i - 1) + isHillVal(i + 1));
        A[i] = flag;

    //    deb(sum);

    }
    if(sum<=0){
        cout<<0<<endl;
    }
    else{
        cout<<sum<<endl;
    }
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