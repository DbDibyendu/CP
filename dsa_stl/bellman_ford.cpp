#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string minTimeToTravelGalaxy(int n, const vector<vector<int>>& flights, int src, int dest) {
        vector<int> dist(n, 1e9);
        
        // CRITICAL FIX: Initialize the starting position!
        dist[src] = 0;

        // Phase 1: Relax edges N-1 times
        for (int i = 0; i < n - 1; i++) { 
            for (auto &f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != 1e9 && dist[v] > dist[u] + w) {
                    dist[v] = w + dist[u]; 
                }
            }
        }

        // Phase 2: N-th time to check for negative cycles
        for (auto &f : flights) {
            int u = f[0], v = f[1], w = f[2];
            if (dist[u] != 1e9 && dist[v] > dist[u] + w) {
                return "PARADOX"; // Negative cycle caught
            }
        }
        
        // Phase 3: Check if unreachable
        if (dist[dest] == 1e9) {
            return "UNREACHABLE";
        }

        // Convert the final integer time to a string
        return to_string(dist[dest]);
    }
};
