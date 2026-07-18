

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

const int N = 1e6 + 100, M = N;
//=======================


class Solution {

  int minMoves(vector<int> arr){
    // running min and max
    // whenever diff btw them breaches 5-> update count
    int count = 0;

    // more of a greedy approach
    // 1 2 3 8 9 3 4 5 7

    int r_max = arr[0], r_min = arr[0];

    int n = arr.size();
    int i,j;
    for(i = 1; i < n; i++){
      
      r_max = max(r_max, arr[i]);
      r_min = min(r_min, arr[i]);

      if(r_max - r_min >= 5){
        // for printing fingers just maintain min and max fingers here and push into pair
        // We can map then from the min and max index back to the fingers
        // update
        r_max = arr[i];
        r_min = arr[i];
        count++;
      }
    }
    // right approach
    return count;
  }

  // 10 fingers : state maintain and keep track of lower bounds 
  int minMovesV2(vector<int> arr){
    // running min and max
    // whenever diff btw them breaches 5-> update count
    int count = INT_MAX;
    // {l1, l2}, and count
    map<pair<int, int>, int> states;

    states[{-1, -1}] = 0;

    for(auto &v: arr){

      // both occupied

    map<pair<int, int>, int> next_states;

      for(auto &[hand_pos, cost]: states){
        int L1 = hand_pos.first;
        int L2 = hand_pos.second;

        int covered_by_1 = (L1 != -1 && v >= L1 && v <= L1+4);
        int covered_by_2 = (L2 != -1 && v >= L1 && v <= L2+4);

        if(covered_by_1 || covered_by_2){
          // note is already covered, update cost

          if(next_states.count({L1,L2})){
            next_states[{L1, L2}] = cost;
          }else{
            next_states[{L1, L2}] = min(next_states[{L1,L2}], cost);
          }

        }else{
          // try both: update 1
          int cost_1 = (L1 == -1 ? 0 : 1); // if free then 0 cost

          for(int new_l1 = v -4; new_l1 <= v;  new_l1++){ // O(5) max
            if(next_states.count({new_l1,L2})){
              next_states[{new_l1, L2}] = cost_1;
            }else{
              next_states[{new_l1, L2}] = min(next_states[{new_l1,L2}], cost_1);
            }
          }


          // and update 2
          int cost_2 = (L1 == -1 ? 0 : 1); // if free then 0 cost

          for(int new_l2 = v -4; new_l2 <= v;  new_l2++){ // O(5)
            if(next_states.count({L1,new_l2})){
              next_states[{L1, new_l2}] = cost_2;
            }else{
              next_states[{L1, new_l2}] = min(next_states[{L1, new_l2}], cost_2);
            }
          }

        }
      }

      // O(25) max states
      states.clear();

      int min_cost = INT_MAX;

      for(auto &[hand_pos, cost] : next_states){
        min_cost = min(cost, min_cost);
      }

      // additional pruning
      for(auto &[hand_pos, cost] : next_states){
        if(cost <=min_cost +2){
          states[hand_pos] = cost;
        }
      // Need to prune as well
    }


    for(auto &[hand_pos, cost] : states){
      count = min(cost, count);
    }
    // TC: O(N*25)
    // SC : O(25)

    // more of a greedy approach
    // 1 2 3 8 9 3 4 5 7
    // right approach
    return count;
  }
  }
};

//=======================
