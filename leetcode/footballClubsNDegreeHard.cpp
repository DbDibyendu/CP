#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

class Solution {
    vector<vector<int>> isSameGrp;
    vector<int> clubs;

    // FIX 1: O(degree * log N) targeted update without iterator invalidation
    void removeFromAdj(int target, unordered_map<int, set<int>> &adj, set<pair<int, int>> &ndegree) {
        if (adj.find(target) == adj.end()) return;

        // Only iterate over target's ACTUAL neighbors, not the whole map
        for (int neighbor : adj[target]) {
            // Update neighbor's degree in ndegree
            ndegree.erase({(int)adj[neighbor].size(), neighbor});
            adj[neighbor].erase(target);
            ndegree.insert({(int)adj[neighbor].size(), neighbor});
        }
        
        adj.erase(target);
    }

    public:
    vector<vector<int>> validFixtures(vector<vector<int>> grps, vector<pair<string, vector<int>>> countries) {
        int max_t = INT_MIN;
        clubs.clear();

        for (auto &g : grps) {
            for (auto team : g) {
                max_t = max(max_t, team);
                clubs.push_back(team);
            }
        }

        int n = clubs.size();
        if (n % 2 != 0) return {}; // Return empty list if odd number of teams

        isSameGrp.assign(max_t + 1, vector<int>(max_t + 1, 0));

        for (auto &g : grps) {
            for (size_t u = 0; u < g.size(); u++) {
                for (size_t v = u + 1; v < g.size(); v++) {
                    isSameGrp[g[u]][g[v]] = 1;
                    isSameGrp[g[v]][g[u]] = 1;
                }
            }
        }

        for (auto &c : countries) {
            auto &teamList = c.second;
            for (size_t u = 0; u < teamList.size(); u++) {
                for (size_t v = u + 1; v < teamList.size(); v++) {
                    isSameGrp[teamList[u]][teamList[v]] = 1;
                    isSameGrp[teamList[v]][teamList[u]] = 1;
                }
            }
        }

        unordered_map<int, set<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int u = clubs[i], v = clubs[j];
                if (!isSameGrp[u][v]) {
                    adj[u].insert(v);
                    adj[v].insert(u);
                }
            }
        }

        // FIX 2: Populate ALL teams into ndegree (including those with 0 degree)
        set<pair<int, int>> ndegree;
        for (int team : clubs) {
            ndegree.insert({(int)adj[team].size(), team});
        }

        vector<vector<int>> final_ans;

        while (!ndegree.empty()) {
            auto top = ndegree.begin();
            int u = top->second;
            int u_deg = top->first;
            ndegree.erase(top);

            // FIX 3: Check if node has 0 valid options left
            if (u_deg == 0 || adj[u].empty()) return {};

            int best_v = -1;
            int v_size = INT_MAX;
            for (auto v : adj[u]) {
                if ((int)adj[v].size() < v_size) {
                    v_size = adj[v].size();
                    best_v = v;
                }
            }

            if (best_v == -1) return {}; // Failed to find opponent

            final_ans.push_back({u, best_v});

            // Erase best_v from ndegree
            ndegree.erase({(int)adj[best_v].size(), best_v});

            // Update remaining graph
            removeFromAdj(best_v, adj, ndegree);
            removeFromAdj(u, adj, ndegree);
        }

        return final_ans;
    }

    // kind of fucked if this kind of question comes
};
