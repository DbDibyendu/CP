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


int findMinTime(vector<int> tasks, int s, int c) {

  sort(tasks.begin(), tasks.end());

  int taskSize = tasks.size();
  int i;

  deque<int> dq;
  for(i=0;i<taskSize;i++){
    if(c>0){
      int endTime= tasks[i] + s; // O(NlogC) or O(N+C)-> monotonic decreasing stack
      dq.push_back(endTime);
      c--;
    }else{
      int lastEndTime = dq.front();
      dq.pop_front();
      int newEndTime = max(tasks[i] + s, lastEndTime + s);
      dq.push_back(newEndTime);
    }
  }

  return dq.back();
}

int findMinCPUs(vector<int> tasks, int s) {

  sort(tasks.begin(), tasks.end());

  int taskSize = tasks.size();
  int i;

  int minTime = tasks.back() + s;

  int l = 1, r = taskSize, mid, ans = taskSize;

  while(l<=r){

    mid = (l+r)/2;
    int midMinTime = findMinTime(tasks, s, mid);
    if(midMinTime <= minTime){
      ans = mid;
       r = mid-1;
    }else{
      l = mid+1;
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
