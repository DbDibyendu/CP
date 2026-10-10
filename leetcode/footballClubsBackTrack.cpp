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
    vector<vector<int>> isSameGrp;
    vector<int> clubs;

    // FIX: dfs now returns bool so it stops early when a solution is found
    bool dfs(int i, vector<int> &vis, vector<vector<int>> &validPairs) {
        int n = clubs.size();

        // Base case: All teams are successfully paired
        if (validPairs.size() == n / 2) return true;

        if(i == n) return false;

        // FIX: If team 'i' is already paired, advance to the next team
        if (vis[i]) return dfs(i + 1, vis, validPairs);

        for (int j = i + 1; j < n; j++) {
            int teamA = clubs[i];
            int teamB = clubs[j];

            // Check if team B is unvisited and there is no country/group conflict
            if (!vis[j] && !isSameGrp[teamA][teamB]) {
                vis[i] = 1;
                vis[j] = 1;
                validPairs.push_back({teamA, teamB}); // FIX: Push actual team IDs

                if (dfs(i + 1, vis, validPairs)) return true; // Stop backtracking on success

                // Backtrack
                validPairs.pop_back();
                vis[i] = 0;
                vis[j] = 0;
            }
        }

        return false;
    }

public:
    vector<vector<int>> validFixtures(vector<vector<int>> grps, vector<pair<string, vector<int>>> countries) {
        int max_t = INT_MIN;
        clubs.clear();

        // Collect all teams and find maximum team ID
        for (auto &g : grps) {
            for (auto team : g) {
                max_t = max(max_t, team); // FIX: Changed 'min' to 'max'
                clubs.push_back(team);
            }
        }

        int n = clubs.size();
        isSameGrp.assign(max_t + 1, vector<int>(max_t + 1, 0));

        // FIX: Nested loops to mark ALL team conflicts within groups
        for (auto &g : grps) {
            for (size_t u = 0; u < g.size(); u++) {
                for (size_t v = u + 1; v < g.size(); v++) {
                    isSameGrp[g[u]][g[v]] = 1;
                    isSameGrp[g[v]][g[u]] = 1;
                }
            }
        }

        // FIX: Nested loops to mark ALL team conflicts within countries
        for (auto &c : countries) {
            auto &teamList = c.second;
            for (size_t u = 0; u < teamList.size(); u++) {
                for (size_t v = u + 1; v < teamList.size(); v++) {
                    isSameGrp[teamList[u]][teamList[v]] = 1;
                    isSameGrp[teamList[v]][teamList[u]] = 1;
                }
            }
        }

        vector<int> vis(n, 0); // Visited state mapped to 'clubs' index (0 to n-1)
        vector<vector<int>> finalResult;

        if (dfs(0, vis, finalResult)) {
            return finalResult;
        }
        // TC: O(N!!) approx -> Double factorial means Odd number of choices -> (N-1_) * (N-3) * (N-5) .... 1
        // SC: O(max_team_id^2 + N) as pasing by reference, at each moment just mainting (N/2) elements in vector with 2 internal pairs -> O(N)

        return {}; // Return empty list if no valid fixture exists
    }
};
//=======================
