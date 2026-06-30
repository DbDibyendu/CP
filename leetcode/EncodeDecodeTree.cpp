
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

long long fact[N];

long long binpow(long long val, long long deg, long long mod) {
  if (!deg)
    return 1 % mod;
  if (deg & 1)
    return binpow(val, deg - 1, mod) * val % mod;
  long long res = binpow(val, deg >> 1, mod);
  return (res * res) % mod;
}

void initfact() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i);
    fact[i] %= MOD;
  }
}

long long C(ll n, ll i) {
  long long res = fact[n];
  long long div = fact[n - i] * fact[i];
  div %= MOD;
  div = binpow(div, MOD - 2, MOD);
  return (res * div) % MOD;
}


class Node {
  public:
  int data;
  int ind;
  // int index; for maintaining unique id
  vector<Node> outEdges;
};


// use dfs for encoding ok, my approach, For Tree like Graph
// index_data_neigherSize->index_data_neighbourSize-> 
// If neigherSize > 0 -> follow with data in similar format for each neigbour branch
//
// For graphs and cyclic graphs
// index_data_neigbherSize_neighbourIndices for cyclic graphs as well

void encodeHelper(Node root, vector<int> nums, vector<int> vis){

    int size = root.outEdges.size();
    nums.push_back(root.ind);
    nums.push_back(root.data);
    nums.push_back(size);
    vis[root.ind]++;

    for(int i=0;i<size;i++){
      if(vis[root.outEdges[i].ind]) continue;

      encodeHelper(root.outEdges[i], nums,vis);
    }
}

void dfsIndex(Node root, int ind, vector<int> nums, vector<int> vis){

    int size = root.outEdges.size();
    root.ind = ind;
    vis[root.ind]++;

    for(int i=0;i<size;i++){
      if(vis[root.outEdges[i].ind]) continue;

      dfsIndex(root.outEdges[i], ind+i, nums,vis);
    }
}

vector<int> encode(Node root) {

  vector<int> nums, vis(100005,0);
  dfsIndex(root, 0, nums, vis);
  vis.assign(1000005, 0);

  encodeHelper(root, nums, vis);

  return nums;
};


int decodeHelper(Node root, int index, vector<int> graph, vector<int> vis){

  root.ind = graph[index];
  root.data = graph[index+1];
  vector<Node> temp(graph[index+2]);
  root.outEdges = temp;
  vis[root.ind] = 1;

  int updatedIndex = index+3;
  for(int i=0;i<graph[index+2];i++){

    if(vis[updatedIndex]) continue;

    updatedIndex = decodeHelper(root.outEdges[i], updatedIndex, graph, vis);
  }

  return updatedIndex;
}


Node decode(vector<int> graph) {

  
  vector<int> vis(100005,0);
  Node root = Node();
  decodeHelper(root, 0, graph, vis);

  return root;
};


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
