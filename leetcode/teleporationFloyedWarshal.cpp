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

// main question

vector<int> dp;
int minBrokenTeleports(int n, vector<vector<int>> tels, vector<int> broken, int start, int dest){

  // bfs approach
  queue<pair<int,int>> q;
  unordered_map<int, int> broken_map;
  dp.assign(n+1, 1e9);
  dp[start] = 0; // FIX: Initialize the starting position distance to 0 so relaxation tracking works correctly

  for(auto a: broken){
    broken_map[a]++;
  }

  q.push({start, 0});

  while(!q.empty()){
    auto top = q.front();
    q.pop();

    if(top.second > dp[top.first]) continue; // same as vis

    for(int neigh: tels[top.first]){
      int count=top.second;
      if(broken_map[neigh]){
        count++;
      }
      if(count < dp[neigh]){
        dp[neigh] = count;
        q.push({neigh, dp[neigh]});
      }
    }
  }

  // FIX: Handle the unreachable edge case just like you beautifully did in V2
  return dp[dest] == 1e9 ? -1 : dp[dest]; 
}


// Follow up 2
vector<int> minBrokenTeleportsV2(int n, vector<vector<int>> tels, vector<int> broken, vector<vector<int>> queries){

  // bfs approach
  queue<pair<int,int>> q;
  unordered_map<int, int> broken_map;
  
  // FIX: This line references the global `dp` vector but is immediately overridden by your local 2D matrix below. Removed to prevent dead code confusion.

  vector<vector<int>> dp(n+1, vector<int>(n+1,1e9));

  // FIX: Base case for Floyd-Warshall. The distance from any teleporter to itself must be 0.
  for(int i = 0; i < n; i++){
    dp[i][i] = 0;
  }

  for(auto a: broken){
    broken_map[a]++;
  }

  // FIX: Cleaned loop configuration up to use `n` instead of tels.size() for consistency
  for(int i=0; i<n; i++){
    // FIX: Changed tels[0].size() to tels[i].size(). 
    // Since each teleporter has a different number of connections, checking row 0's size every time causes out-of-bounds or missed neighbors.
    for(int j=0; j<tels[i].size(); j++){ 
      if(broken_map[tels[i][j]]){
        dp[i][tels[i][j]] = 1;
      }else{
        dp[i][tels[i][j]] = 0;
      }
    }
  }

  int i,j,k;
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        // FIX: Added an infinity guard check. This prevents adding two 1e9 values together, which avoids unintended value wrap-arounds.
        if(dp[k][j] != 1e9 && dp[i][k] != 1e9){
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
  }

  vector<int> ans;
  for(auto q: queries){
    if(dp[q[0]][q[1]] == 1e9) ans.push_back(-1);
    else ans.push_back(dp[q[0]][q[1]]);
  }

  return ans;
}
