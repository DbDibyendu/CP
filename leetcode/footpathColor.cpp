#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int GetBeautyValue(const int n, int k, int c, vector<int> &block_color){

  int beautyValue = -1e9;

  if(c > k) return 0;
  int i;
  int count = 0;
  for(i=0;i<n;i++) if(block_color[i] == c) count = 1;
  // no color c
  if(count == 0) return 0;

  for(i=1;i<n;i++){
    if(block_color[i] == c && block_color[i] == block_color[i-1]){
      count++;
    }else{
      // reset
      beautyValue = max(beautyValue, count);
      count = 1;
    }
  }
  beautyValue = max(beautyValue, count);

  return beautyValue;
}

// follow up 1
vector<int> GetBeautyValueV2(const int n, int k, vector<int> &block_color, vector<int> &queries){

  int i,j;
  vector<int> beautyValue(30,0);
  for(i=1;i<=k;i++){ // O(K*N)
    beautyValue[i] = GetBeautyValue(n, k, i, block_color);
  }

  vector<int> ans;
  // O(Q)
  for(auto q: queries){
    ans.push_back(beautyValue[q]);
  }

  return ans;
}


// follow up 2
// Actually simple : for contiguous prblms, 
// rembmer to start with 2 pointers, queue, monotonic stack, hashmap and then binary search
int getmaximumbeautyvalue(const int n, const int k, const int c, const int m,
                          const std::vector<int>& block_color) {
  // implement

  int max_b_value = -1e9;

  int i,j;

  int repaint_count=0;
  i=0;
  for(j=0;j<n;j++){
    if(block_color[j] != c){
      repaint_count++;
    }

    // shring window
    while(i<n && repaint_count > m){
      if(block_color[i] != c){
        repaint_count--;
      }
      i++;
    } 
    max_b_value = max(max_b_value, j-i+1);
  }

  return max_b_value;
}


// follow up 4
int getmaximumbeautyvalueV2(const int n, const int k, const int c, const int m,
                          const std::vector<int>& block_color) {
  // implement

  int max_b_value = -1e9;

  int i,j, j2;

  int repaint_count=0;
  i=0;
  // should take care of circular
  for(j=0;j<2*n;j++){

    if(block_color[j%n] != c){
      repaint_count++;
    }

    // shring window
    while((i<2*n && repaint_count > m) || (j-i+1>n && i<2*n)){
      if(block_color[i%n] != c){
        repaint_count--;
      }
      i++;
    } 
    max_b_value = max(max_b_value, j-i+1);
  }

  return max_b_value;
}

// follow up 3
vector<int> GetMaximumBeautyValuesV2(const int n, const int k,
                                        vector<int>& m,
                                        vector<int>& favorite_colors,
                                        vector<int>& block_color) {
  // implement
  int i,j,p;
  vector<vector<int>> dp(k+1, vector<int>(n+1,0));

  int repaint_count=0;
  i=0;
  // for different colors as well as different m
  for(p=0;p<= k;p++){
  for(int t=0;t<=n;t++){
    int max_b_value = getmaximumbeautyvalueV2(n, k, p, t, block_color);
    dp[p][t] = max_b_value;
    }
  }

  int size = favorite_colors.size();
  vector<int> ans;
  for(i=0;i<size;i++){
    ans.push_back(dp[favorite_colors[i]][m[i]]);
  }

  return ans;
}
