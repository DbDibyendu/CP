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


vector<int> isPathExist(vector<int> arr, int d, vector<vector<int>> queries){

  // x1-x2 < d

  struct Bucket {
    int min_i;
    int max_i;
  };

  unordered_map<int,Bucket> buckets;
  int i,j;
  int n = arr.size();
  for(i=0;i<n;i++){
    int id = arr[i]/(d+1);
    buckets[id].min_i = min(arr[i], buckets[id].min_i); // assinged buckets
    buckets[id].max_i = max(arr[i], buckets[id].max_i);
  }

  unordered_map<int, int> coloredBuckets;

  int k=0;
  for(i=0;i<n;i++){
    int id = arr[i]/(d+1);
    
    if(coloredBuckets.count(id) > 0) continue;

    k++;
    // assign colours 
    // check if lower neighbour connected
    while(coloredBuckets.count(id-1) == 0 && buckets[id].max_i - buckets[id-1].min_i <= d){
        coloredBuckets[id] = k;
      id--;
    }

    id = arr[i]/(d+1);

    while(coloredBuckets.count(id+1) == 0 && buckets[id+1].min_i - buckets[id].max_i <= d){
      coloredBuckets[id] = k;
      id++;
    }
  }

  vector<int> ans;
  for(i=0;i<queries.size();i++){
    int t = false;
    if(coloredBuckets[queries[0][1]] == coloredBuckets[queries[0][0]]){
      t = true;
    }
    ans.push_back(t);
  }

  return ans;
}

// alternatively can use bfs
struct Bucket {
    int min_val = int(1e9);
    int max_val = int(-1e9);
    vector<int> original_indices; // Track which original array nodes belong here
};

vector<int> isPathExistV2(vector<int> arr, int diff, vector<vector<int>> queries) {
    int n = arr.size();
    if (n == 0) return vector<int>(queries.size(), false);

    // Step 1: Handle negative numbers by shifting all values to be >= 0
    int min_element = arr[0];
    for (int x : arr) min_element = min(min_element, x);

    // Step 2: Populate buckets in O(N) time
    // Bucket width is (diff + 1) to guarantee internal connectivity
    long long bucket_width = (long long)diff + 1;
    unordered_map<long long, Bucket> buckets;

    for (int i = 0; i < n; i++) {
        long long shifted_val = (long long)arr[i] - min_element;
        long long bucket_id = shifted_val / bucket_width;

        buckets[bucket_id].min_val = min(buckets[bucket_id].min_val, arr[i]);
        buckets[bucket_id].max_val = max(buckets[bucket_id].max_val, arr[i]);
        buckets[bucket_id].original_indices.push_back(i);
    }

    // Step 3: Global Component Coloring via Linear BFS over active buckets
    unordered_map<int, int> node_to_component;
    unordered_map<long long, bool> visited_buckets;
    int component_id = 0;

    for (auto const& [bucket_id, _] : buckets) {
        if (visited_buckets[bucket_id]) continue;

        component_id++;
        queue<long long> q;
        
        q.push(bucket_id);
        visited_buckets[bucket_id] = true;

        while (!q.empty()) {
            long long curr_id = q.front();
            q.pop();

            // Color all original nodes inside this bucket
            for (int idx : buckets[curr_id].original_indices) {
                node_to_component[idx] = component_id;
            }

            // Check Left Neighbor Bucket (curr_id - 1)
            if (buckets.count(curr_id - 1) && !visited_buckets[curr_id - 1]) {
                // Connection condition: Gap between buckets must be <= diff
                if (buckets[curr_id].min_val - buckets[curr_id - 1].max_val <= diff) {
                    visited_buckets[curr_id - 1] = true;
                    q.push(curr_id - 1);
                }
            }

            // Check Right Neighbor Bucket (curr_id + 1)
            if (buckets.count(curr_id + 1) && !visited_buckets[curr_id + 1]) {
                // Connection condition: Gap between buckets must be <= diff
                if (buckets[curr_id + 1].min_val - buckets[curr_id].max_val <= diff) {
                    visited_buckets[curr_id + 1] = true;
                    q.push(curr_id + 1);
                }
            }
        }
    }

    // Step 4: Resolve queries in O(1) constant time each
    vector<int> ans;
    ans.reserve(queries.size());
    for (const auto& query : queries) {
        int u = query[0];
        int v = query[1];
        
        if (node_to_component[u] == node_to_component[v]) {
            ans.push_back(true);
        } else {
            ans.push_back(false);
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
