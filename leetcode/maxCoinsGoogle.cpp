/*#include <bits/stdc++.h>*/
#include <iostream>
#include <unordered_map>
#ifndef _GLIBCXX_NO_ASSERT
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
#endif

using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;
#define displayP(A)                                                            \
  for (auto &aa : A) {                                                         \
    display(aa);                                                               \
  }
#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
//=======================



// very tough question, to use dikjstra
// Use bucket queue here, as the cost is limited to K.
int maxCoinsGoogle(int n, vector<vector<int>> coins, int k) {


  priority_queue<tuple<int,int,int>> pq;
  vector<vector<int>> dist(n+1, vector<int>(2, 1e9));

  int i, j;
  int ans = -1e9;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){

      int sum = coins[i][j];
      dist.assign(n+1, vector<int>(2, 1e9));
      dist[i][j] = 0;
      pq.push({0, i, j});

      while(!pq.empty()){
        auto [cost, x, y] = pq.top();
        pq.pop();

        cost = -cost;
        // early pruning
        if(cost > dist[x][y]) continue;
        sum += coins[x][y];

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for(int l = 0; l<4; l++){
          int nx = dx[l] + x;
          int ny = dy[l] + y;
          if(nx<0 || nx>= n || ny<0 || ny>=0) continue;

          int edgeCost = max({x, y, nx, ny});
          if(dist[nx][ny] > dist[x][y] + edgeCost){
            dist[nx][ny] = dist[x][y] + edgeCost;
            pq.push({-dist[nx][ny], nx, ny});
          }
        } 
      }
      ans = max(ans, sum);
    }
  }

  return ans;
}


// Bucket queue
int maxCoinsGoogleV2(int n, vector<vector<int>> coins, int k) {


  vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));

  unordered_map<int, vector<pair<int,int>>> bucket;

  int i, j;
  int ans = -1e9;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){

      int sum = coins[i][j];
      dist[i][j] = 0;

      bucket[0].push_back({i,j});

      vector<pair<int,int>> vis;
      
      for(int m = 0 ; m <= k; m++){
        while(!bucket[m].empty()){
        auto [x, y] = bucket[m].back();
        vis.push_back({x,y});

        bucket[m].pop_back();

        // early pruning
        if(m > dist[x][y]) continue;
        sum += coins[x][y];

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for(int l = 0; l<4; l++){
          int nx = dx[l] + x;
          int ny = dy[l] + y;
          if(nx<0 || nx>= n || ny<0 || ny>=n) continue;

          int edgeCost = max({x, y, nx, ny});
          if(dist[nx][ny] > dist[x][y] + edgeCost){
            dist[nx][ny] = dist[x][y] + edgeCost;
            bucket[dist[nx][ny]].push_back({nx,ny});
            }
          } 
        }
      }

      // reset dist
      while(!vis.empty()){
        auto [x,y] = vis.back();
        vis.pop_back();
        dist[x][y] = 1e9;
      }

      ans = max(ans, sum);
    }
  }

  return ans;
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
  }
  return 0;
}

//=======================
