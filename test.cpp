#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fill(x, y) memset(x, y, sizeof(x))
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ff(j, n) for (int i = j; i < n; i++)
#define fb(j, n) for (int i = n - 1; i >= j; i--)
//int par[200001][2] = {0};
//long long int dp[2000][A2000];
//int prime[20000001];
//int findp(int n){
//if(par[n][0]==n){
//return n;
//}
//return findp(par[n][0]);
//}
//void SieveOfEratosthenes(int n)
//{
//  memset(prime, 0, sizeof(prime));
//for (int p=2; p*p<=n; p++)
//{
//  if (prime[p] == 0 )
//{
//  for (int i=p*p; i<=n; i += p)
//    if(prime[i]==0)
//    prime[i] = p;
//}
//}
//}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}
long long int max(long long int a, long int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
long long int min(long long int a, long long int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    //t =1;
    int w1 = 0;
    while (w1 < t)
    {

        w1++;
        long long int n, m;
        cin >> n;

        long long int a[n] = {0};
        ff(0, n)
        {
            cin >> a[i];
        }
        vector<pair<long long int, long long int>> v;
        long long int l = 2;
        long long int lmax = 2;
        long long int ans = 0;
        long long int dif = a[1] - a[0];
        ff(2, n)
        {
            if (a[i] - a[i - 1] != dif)
            {
                v.pb(mp(l, dif));
                if (l > lmax)
                    lmax = l;
                l = 2;
                dif = a[i] - a[i - 1];
                if (i == n - 1)
                {
                    v.pb(mp(l, dif));
                    if (lmax < l)
                        lmax = l;
                }
            }
            else
            {
                l++;
                if (i == n - 1)
                {
                    v.pb(mp(l, dif));
                    if (lmax < l)
                        lmax = l;
                }
            }
        }
        int z = v.size();
        //cout<<v.size()<<endl;
        ff(0, z)
        {
            if (i < n - 2 && v[i + 1].first == 2 && v[i + 1].second + v[i + 2].second == 2 * v[i].second)
            {
                if (i < n - 3 && v[i].second == v[i + 3].second && v[i + 2].first == 2)
                {
                    long long int x = v[i].first + v[i + 3].first;
                    if (x > lmax)
                        lmax = x;
                }
                else
                {
                    long long int x = v[i].first + 1;
                    if (x > lmax)
                        lmax = x;
                }
            }

            if (i > 1 && v[i - 1].first == 2 && v[i - 1].second + v[i - 2].second == 2 * v[i].second)
            {

                long long int x = v[i].first + 1;
                if (x > lmax)
                    lmax = x;
            }
        }
        cout << "Case #" << w1 << ": ";
        if (lmax == n)
            lmax--;
        cout << lmax + 1;
        cout << endl;
    } //t

    return 0;
}