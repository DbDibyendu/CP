#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


class Solution{


  vector<pair<int, vector<int>>> points = {
    {6, {6}},
    {7, {6,1}},
    {8, {6,2}},
    {3, {3}}
  };

  vector<vector<int>> result;

  void dfs(int score, vector<int> &path){

    if(score < 3) return;

    if(score == 0){
      result.push_back(path);
    }

    // case
    for(auto &p: points){

      int curr_score = p.first;

      for(auto &t : p.second){
        path.push_back(t);
      }
      dfs(score - curr_score, path);
      // backtrack
      for(auto &t : p.second){
        path.pop_back();
      }
    }
    
  }
// FIX: Renamed from 'map' to 'memo' to avoid confusion with std::map
    unordered_map<int, vector<vector<int>>> memo; 

    vector<vector<int>> dfs2(int score) {
        // FIX 1: Moved score == 0 to the very top. 
        // If we reach exactly 0, it means we found a valid combination.
        if (score == 0) {
            return {{}}; // Returns a vector containing an empty vector to kickstart appending
        }

        // FIX 2: Changed from 'score < 3' to 'score < 0'. 
        // Checking '< 0' safely aborts paths that overshoot the target score.
        if (score < 0) {
            return {}; 
        }

        // FIX 3: Updated to use the renamed 'memo' container
        if (memo.count(score)) {
            return memo[score];
        }

        vector<vector<int>> final_path; 
        
        for (auto &p : points) {
            vector<int> curr_path = p.second, prev_path;
            int curr_score = p.first;

            auto next_paths = dfs2(score - curr_score); 

            prev_path = curr_path;

            for (auto &n : next_paths) { 
                for (auto &el : n) {
                    curr_path.push_back(el);
                }
                final_path.push_back(curr_path);
                curr_path = prev_path; // reset
            }
        }

        // FIX 4: Crucial DP Step. Store the calculated paths for the 
        // current score into the memo map before returning.
        memo[score] = final_path; 
        
        // TC: O(paths * score) OR O(total paths * N/3)
        // SC: O(paths * score) OR O(total paths * N/3)
        return final_path;
    }

  vector<vector<int>> getScoreCombinations(int n){


    vector<int> path;
    dfs(n, path);
    vector<vector<int>> result2 = dfs2(n);
    // TC : O(4^(N/3))
    // SC: O(total valid paths + paths ~= (N/3))
    return result;
  }

};
