
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
//=======================
const int MOD = 1'000'000'007;
//=======================



// monotonic stack solution is beautiful here, 
// legacy liquidity prblm 2
int maxGapDuration(vector<int> nums){

  stack<int> st;

  int i, n= nums.size();

  for(i=0;i<n;i++){
    if(st.empty() || nums[i] > nums[st.top()]){
      st.push(i);
    }
  }

  int maxDist = 0;

  for(i=n-1; i>=0; i--){
    while(!st.empty() && nums[st.top()] > nums[i]){
      int j = st.top();
      st.pop();
      maxDist = max(maxDist, j-i);
    }
  }
  return maxDist;
}

// legacy liquidity prblm 3
// Beautiful Divide and conquer, mergesort

int merge(int L, int R, int mid, vector<int> &nums, int df){

  int count = 0;

  int n = nums.size();
  int k=0;
  int l = L, r = mid;
  vector<int> temp = nums;
  
  // count inversions
  

  int i, j = mid;
  // 2 pointers
  for(i=l;i<mid;i++){ // for each i add j max possible value
    while(nums[i] > nums[j]*df && j<R){
      j++;
    }
    count += (j-mid);
  }

  // merge O(N)
  while(l < mid && r < R){
    if(temp[l] < temp[r]){
      nums[k] = temp[l];
      l++;
      k++;
    }else{
      nums[k] = temp[r];
      r++;
      k++;
    }
  }

  while(l< mid){
      nums[k] = temp[l];
      l++;
      k++;
  }

  while(r<R){
      nums[k] = temp[r];
      r++;
      k++;
  }

  // fill either right or left remaining
  return count;
};

int inversionCount(int l, int r, vector<int> &nums, int df){

  if(l>r) return 0;
  int mid = (l+r)/2;
  int count = 0;
  count += inversionCount(mid+1, r, nums, df);
  count += inversionCount(l, mid, nums, df);

  count += merge(l, r, mid, nums, df);

  return count;
}

bool isLiquidityParadox(vector<int> nums, int df, int vl){

  int n = nums.size();

  int k = inversionCount(0, n, nums, df);

  if( k >= vl)  return true;

  return false;
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
