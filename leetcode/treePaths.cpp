
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




vector<int> numberOfValidPaths(int n, vector<vector<int>>& edges, string nodeS, string M) {
    int m = M.length();
    if (m == 0) return {};

    // FIX 1: Properly size the adjacency list to avoid Segmentation Faults
    vector<vector<int>> adj(n);
    for (auto e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // Structure to track each unique path state in the queue
    struct PathState {
        int curr;
        int parent;
        int depth;
    };

    vector<PathState> q;
    vector<int> ans(m, 0);

    for (int i = 0; i < n; i++) {
        if (M[0] == nodeS[i]) {
            q.push_back({i, -1, 0}); // Node index, Parent (-1 means no parent), Depth 0
        }
    }

    while (!q.empty()) {
        auto [curr, par, depth] = q.back(); 
        q.pop_back();

        ans[depth]++;

        if (depth + 1 == m) continue;

        for (auto neighbor : adj[curr]) {
            if (neighbor != par && nodeS[neighbor] == M[depth + 1]) { // neighbor is important
                q.push_back({neighbor, curr, depth + 1});
            }
        }
    }

    // Time O(N)
    // Space O(N)

    return ans;
}


vector<int> numberOfValidPathsV2(int n, vector<vector<int>>& edges, string nodeS, string M) {
    int m = M.length();
    if (m == 0) return {};

    vector<vector<int>> adj(n);
    for (auto e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    struct PathState {
        int curr;
        int parent;
    };

    queue<PathState> q;
    vector<int> ans;
    
    bool isFirstCharacter = true;

    for (char ch : M) {
        int count = 0;

        if (isFirstCharacter) {
            for (int i = 0; i < n; i++) {
                if (nodeS[i] == ch) {
                    q.push({i, -1}); // -1 signifies no incoming parent history
                    count++;
                }
            }
            isFirstCharacter = false; // Wavefront is successfully initialized
        } 
        else {
            // EXPANSION PHASE: Advance the active wavefront exactly one level deep
            int sz = q.size(); // Snapshot size to isolate the current stream layer

            for (int i = 0; i < sz; i++) {
                auto [curr, par] = q.front(); 
                q.pop();

                for (auto neighbor : adj[curr]) {
                    if (neighbor != par && nodeS[neighbor] == ch) {
                        q.push({neighbor, curr});
                        count++;
                    }
                }
            }
        }
        
        ans.push_back(count);
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
