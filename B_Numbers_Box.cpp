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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
int i, j, n, m, k;
//=======================

void solve()
{
    long long int sum2 = 0;
    int c = 0,min=0;
    cin >> n >> m;
    int c0;
    vector<vi> A(n);
    vector<vi> B(m);
    fo(i, n)
    {
        A[i] = vector<int>(m); // declaring 2d vectors
        fo(j, m)
        {
            cin >> A[i][j];
            if (A[i][j] < 0)
                c++;
        }
    }
    if (c % 2 == 0)
    {
        fo(i, n)
        {
            int sum1 = 0;
            fo(j, m)
            {
                if (A[i][j] < 0)
                {
                    A[i][j] *= -1;
                }
                   
            }
             sum1 = accumulate(A[i].begin(), A[i].end(), 0);
            sum2 += sum1;
        }
    }

    else if (c % 2 != 0)
    {
        min= 100000;
        fo(i, n)
        {
            int sum1 = 0;
            fo(j, m)
            {
                if (A[i][j] < 0)
                {
                    A[i][j] *= -1;
                }

            }
              sort(A[i].begin(),A[i].end());
                
                k=A[i][0];
                if(k<min){
                    min=k;
                }
              sum1 = accumulate(A[i].begin(), A[i].end(), 0);
    
            sum2 += sum1;
        }
    }

    cout << sum2 -(2*min)<< endl;
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