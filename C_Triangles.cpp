#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = 100005;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k;
    cin >> n;
    string arr[n];
    ll A[n][n];
    fo(i, n)
    {
        cin >> arr[i];
    }
    int max_row[10] = {0}, min_row[10], max_column[10] = {0}, min_column[10];
    fo(i,10){
        min_column[i]=INT_MAX;
        min_row[i]=INT_MAX;

    }

    fo(i, n)
    {
        fo(j, n)
        {
            int x = arr[i][j] - '0';
            max_row[x] = max(max_row[x], i);
            min_row[x] = min(min_row[x], i);
            max_column[x] = max(max_column[x], j);
            min_column[x] = min(min_column[x], j);
        }
    }

    int Ans[10] = {0};
    fo(i, n)
    {
        fo(j, n)
        {
            int x = arr[i][j] - '0';
            Ans[x] = max(Ans[x], max(i, n - i - 1) * max(max_column[x] - j, j - min_column[x]));
            Ans[x] = max(Ans[x], max(j, n - j - 1) * max(max_row[x] - i, i - min_row[x]));
        }
    }
    fo(i, 10) cout << Ans[i] << " ";

    cout << endl;
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