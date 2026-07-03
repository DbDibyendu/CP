#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

// important to use unoredered_set
vector<unordered_set<int>> adj;

class DSU {
  public:
    int size=0;
    vector<int> par;
    DSU(int n){
      par.resize(n + 1);
      int i;
      for(i=1;i<=n;i++){
        par[i]=i;
        size++;
      }
    }

    void unite(int a, int b){
      int parA = query(a);
      int parB = query(b);
      if(parA != parB){
        par[parA] = parB;
        size--;
      }
    }

    int query(int x){
      if(par[x] == x) return x;
      return par[x] = query(par[x]);
    }
};

bool isConnectedBfsHelper(int a, int b, int n){
  queue<int> q;
  vector<int> vis(n+1, 0);
  q.push(a);
  vis[a] = 1;

  while(!q.empty()){
    int t = q.front();
    q.pop();

    if(t == b) return true;

    for(auto nhbr: adj[t]){
      if(vis[nhbr] == 0){
        vis[nhbr] = 1;
        q.push(nhbr);
      }
    }
  }
  return false;
}

int earliestTime(vector<int> frnds, vector<vector<int>> logs){
  int n = frnds.size();
  DSU* dsu = new DSU(n);
  adj.assign(n+1, unordered_set<int>()); 

  for(auto l : logs){
    int ts = l[0];
    int u1 = l[1];
    int u2 = l[2];
    int type = l[3];

    if(type == 1){
      if(dsu->query(u1) != dsu->query(u2)){
          dsu->unite(u1, u2);
      }
      adj[u1].insert(u2);
      adj[u2].insert(u1);
    }else{
      adj[u1].erase(u2);
      adj[u2].erase(u1);
      
      if(!isConnectedBfsHelper(u1, u2, n)){
        DSU* dsu2 = new DSU(n);
        for(int i = 1; i <= n; i++){
          for(auto nhbr : adj[i]){
              dsu2->unite(i, nhbr);
          }
        }
        delete dsu;
        dsu = dsu2;
      }
    }

    if(dsu->size == 1){
      delete dsu;
      return ts;
    }
  }

  delete dsu;
  return -1;
}
