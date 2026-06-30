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

#define display(A)                                                             \
  for (auto &aa : A)                                                           \
    cout << aa << ' ';                                                         \
  cout << endl;

#define read(A)                                                                \
  for (auto &aa : A) {                                                         \
    cin >> aa;                                                                 \
  }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
//=======================
//
const int MOD = 1000000007;
const int N = 1000007, M = N;
//=======================


vector<int> distFromA;
vector<vector<vector<int>>> adj;
vector<int> vis;

// edge cases no solution, disjoint graph
pair<int, int> fastestRoute(
    int n,
    vector<vector<int>>& edges,
    vector<int>& favorites,
    int source = 0
) {
    // adj[u] = {v, weight}
    vector<vector<pair<int, int>>> adj(n);

    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
    }

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) { // O(NlogN)
        auto [currDist, u] = pq.top();
        pq.pop();

        currDist = -currDist;

        if (currDist > dist[u]) // we don't need vis array seperately
            continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({-dist[v], v});
            }
        }
    }

    int bestCity = -1;
    int bestTime = INT_MAX;

    for (int city : favorites) {
        if (dist[city] < bestTime) {
            bestTime = dist[city];
            bestCity = city;
        }
    }

    // edge cases
    if(bestTime == INT_MAX) return {-1, -1};

    // time O(V+E)Log(V)
    // Space O(V+E)
    return {bestCity, bestTime};
}

// follow up 1, city goes through B, suppose B is 

pair<int, int> fastestRouteThroughB(
    int n,
    vector<vector<int>>& edges,
    vector<int>& favorites,
    int source = 0,
    int B = 3
) {
    // adj[u] = {v, weight}
    vector<vector<pair<int, int>>> adj(n);

    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
    }

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) { // O(NlogN)
        auto [currDist, u] = pq.top();
        pq.pop();

        currDist = -currDist;

        if (currDist > dist[u]) // we don't need vis array seperately
            continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({-dist[v], v});
            }
        }
    }

    int distanceFromAtoB = dist[B];

    if(distanceFromAtoB == INT_MAX) return {-1, -1};



    // run bfs again for source B
    dist.assign(n,INT_MAX);
    dist[B] = 0;
    pq = priority_queue<pair<int,int>>();

    pq.push({0, B});

    while (!pq.empty()) { // O(NlogN)
        auto [currDist, u] = pq.top();
        pq.pop();

        currDist = -currDist;

        if (currDist > dist[u]) // we don't need vis array seperately
            continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({-dist[v], v});
            }
        }
    }


    int bestCity = -1;
    int bestDist = INT_MAX;

    for (int city : favorites) {
        if(dist[city] == INT_MAX)
            continue;
        if (dist[city] < bestDist) {
            bestDist = dist[city];
            bestCity = city;
        }
    }

    if(bestDist == INT_MAX) return {-1, -1};

    return {bestCity, bestDist + distanceFromAtoB};
}

// 2: Follow up
// Last dest B, touching any of the fav cities. 
// 2 solution possible, run 2 bfs or run state dijkstra 

// trying state dijkstra here
int fastestRouteViaFavs(
    int n,
    vector<vector<int>>& edges,
    vector<int>& favorites,
    int source = 0,
    int B=4
) {
    // adj[u] = {v, weight}
    vector<vector<pair<int, int>>> adj(n);

    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
    }

    // map of favs
    unordered_map<int,int> mp;

    for(auto a: favorites){
      mp[a]++;
    }

    // maintain vistiedFav state as 2nd index
    vector<vector<int>> dist(n,vector<int> (2,INT_MAX));

    priority_queue<tuple<int,int,int>> pq;

    dist[source][0] = 0;
    pq.push({0, source, 0});

    while (!pq.empty()) { // O(NlogN)
        auto [currDist, u, visitedFav] = pq.top();
        pq.pop();

        currDist = -currDist;

        if (currDist > dist[u][visitedFav]) // we don't need vis array seperately
            continue;

        for (auto [v, weight] : adj[u]) {
            int nextFav = visitedFav || mp[v];

            // distance is more of a dp, so maintain state dp
            if (dist[v][nextFav] > dist[u][visitedFav] + weight) {
                dist[v][nextFav] = dist[u][visitedFav] + weight;
                pq.push({-dist[v][nextFav], v, nextFav});
            }
        }
    }


    if(dist[B][1] == INT_MAX) return -1; // no solution

    // time O(V+E)Log(V)
    // Space O(V+E)
    return dist[B][1];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  /*cin >> t;*/
  while (t--) {
  }
  return 0;
}
