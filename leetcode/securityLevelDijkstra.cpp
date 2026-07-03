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


// declare struct for better readability
struct Edge {
    int to;
    int security;
    int length;
};

vector<vector<Edge>> adj;
vector<int> dist;
vector<int> dist2;

int minSecurityLevel(int nodes, vector<vector<int>> edges, int st, int end) {
    
    // Step 1: Initialize structures to hold neighbor, security, and length
    adj.assign(nodes + 1, vector<Edge>());
    dist.assign(nodes + 1, INT_MAX);

    for (auto e : edges) {
        // e[0] = from, e[1] = to, e[2] = security, e[3] = length
        adj[e[0]].push_back({e[1], e[2], e[3]});
    }

    // PASS 1: Find the absolute minimum security level bottleneck
    priority_queue<pair<int, int>> pq;
    dist[st] = 0;
    pq.push({0, st});

    int minSecurity = 1e9;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int currSec = -top.first; 
        int currNode = top.second;

        if (currNode == end) {
            minSecurity = dist[currNode];
            break;
        }

        if (currSec > dist[currNode]) continue;

        for (auto a : adj[currNode]) {
            int newSec = max(dist[currNode], a.security);
            if (newSec < dist[a.to]) {
                dist[a.to] = newSec;
                pq.push({-newSec, a.to});
            }
        }
    }

    // If no valid path exists to the destination, return -1
    if (minSecurity == 1e9) return -1;

    // PASS 2: Find the shortest path length, filtered by minSecurity
    dist2.assign(nodes + 1, INT_MAX);
    while (!pq.empty()) pq.pop(); // Clear queue safely

    vector<int> par(nodes+1, -1);
    dist2[st] = 0;
    pq.push({0, st});
    // track path

    int shortestPath = 1e9;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currDist = -top.first; 
        int currNode = top.second;

        if (currNode == end) {
          shortestPath = dist2[currNode];
          break;
        }

        if (currDist > dist2[currNode]) continue;

        for (auto a : adj[currNode]) {
            // CRUCIAL FIX: Only traverse this edge if its specific security level is allowed
            if (a.security <= minSecurity) {
                int nextDist = dist2[currNode] + a.length;
                if (nextDist < dist2[a.to]) {
                    dist2[a.to] = nextDist;
                    par[a.to] = currNode;
                    pq.push({-nextDist, a.to});
                }
            }
        }
    }

    if(shortestPath == 1e9) return -1;

    vector<int> path;

    int index = end;
    path.push_back(end);

    while(par[index] != -1){
      path.push_back(par[index]);
      index = par[index];
    }

    reverse(path.begin(), path.end());
    for(auto a: path){
      cout<<a<<endl;
    }
    return shortestPath;
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
