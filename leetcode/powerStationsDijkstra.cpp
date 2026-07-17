#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Rate{
  int from;
  int to;
  float efficiency;
  int cost;
};


struct Node{
  int node;
  float efficiency;
  int cost;
};

float efficiencyRating(int n, vector<Rate> transimissions, int source, int dest){

  vector<vector<Node>> adj(n + 1);
  for(auto e: transimissions){
    adj[e.from].push_back({e.to, e.efficiency});
  }


  vector<float> dist(n+1, 0);

  priority_queue<pair<float, int>>pq;

  dist[source] = 1;
  pq.push({1, source});

  while(!pq.empty()){
    auto [currEf, currNode] = pq.top();
    pq.pop();

    // as it's a Max Heap solution, dist[currNode] means already found best distance for currNode
    if(dist[currNode] > currEf ) continue; // important for pruning

    if(currNode == dest) return dist[currNode];


    for(auto a: adj[currNode]){
      float newEff = currEf*a.efficiency;
      int newNode = a.node;
      if(dist[newNode] < newEff){
        dist[newNode] = newEff;
        pq.push({newEff, newNode});
      }
    }
  }

  // Time complexity : O(V+E)logV
  // Space complexity : O(V+E)
}

// follow up 1 is easy, just pick the neighbour node with the max efficiency
// By creating a reverse graph, from destination to source directed



// follow up 2, even number of nodes
// This parity distance is valid in many of the question. Remember it
// Simply adding a dimension solves the prblm
float efficiencyRatingV2(int n, vector<Rate> transimissions, int source, int dest) {
    vector<vector<Node>> adj(n + 1);
    for(auto e: transimissions){
        adj[e.from].push_back({e.to, e.efficiency});
    }

    // 2D distance tracking: dist[node][0] for even paths, dist[node][1] for odd paths
    vector<vector<float>> dist(n + 1, vector<float>(2, 0.0f));
    priority_queue<tuple<float, int, int>> pq;

    dist[source][0] = 1.0f;
    pq.push({1.0f, source, 0}); 

    while(!pq.empty()){
        auto [currEf, currNode, parity] = pq.top();
        pq.pop();

        // Prune stale states
        if(currEf < dist[currNode][parity]) continue;

        // The exact moment we extract the destination with an even parity (0), it is optimal
        if(currNode == dest && parity == 0) return currEf;

        for(auto a: adj[currNode]){
            float newEff = currEf * a.efficiency;
            int newNode = a.node;
            int nextParity = 1 - parity; // Alternates between 0 (even) and 1 (odd)

            // Relax the neighbor only for its specific incoming parity state
            if(dist[newNode][nextParity] < newEff){
                dist[newNode][nextParity] = newEff;
                pq.push({newEff, newNode, nextParity});
            }
        }
    }

    return 0.0f;
}


// think carefully, these extra dimensions, should be extra states in ur dist vector. Which is like a dp
float efficiencyRatingV3(int n, vector<Rate> transimissions, int source, int dest, int maxCost){

  vector<vector<Node>> adj(n + 1);
  for(auto e: transimissions){
    adj[e.from].push_back({e.to, e.efficiency, e.cost});
  }


  vector<vector<float>> dist(n+1, vector<float>(maxCost,0));

  priority_queue<tuple<float, int, int>>pq;

  dist[source][0] = 1;
  pq.push({1, source, 0});

  while(!pq.empty()){
    auto [currEf, currNode, currCost] = pq.top();
    pq.pop();

    if(dist[currNode][currCost] > currEf ) continue;

    if(currNode == dest) return dist[currNode][currCost];


    for(auto a: adj[currNode]){
      float newEff = currEf*a.efficiency;
      int newNode = a.node;
      int newCost = currCost + a.cost;
      if(newCost <= maxCost && dist[newNode][newCost] < newEff){
        dist[newNode][newCost] = newEff;
        pq.push({newEff, newNode, newCost});
      }
    }
  }

  // TC: O((V+E)*maxCost*Log(V*maxCost))
  // Space : O(maxCost*N + (V+E));
}

