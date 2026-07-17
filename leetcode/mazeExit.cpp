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

// main question

enum NodeType {
  AND,
  OR,
  XOR,
  NOT,
  BOOLEAN
};

class Maze{
// FIX: Added public specifier so your runner can call exitCommand outside the class
public: 

  string currCommand;
  vector<vector<int>> vis;
  map<char, vector<int>> dir;

  Maze(){
    currCommand = "";
    // FIX: Corrected direction values to match a standard 2D matrix grid coordinate layout
    // In grid indexing, 'U' decreases the row index, 'D' increases the row index, 
    // 'L' decreases the column index, and 'R' increases the column index.
    dir = {
        {'R', {0, 1}},
        {'L', {0, -1}},
        {'U', {-1, 0}},
        {'D', {1, 0}}
    };
  }

  pair<bool, vector<int>> prevCommandTraverse(int x, int y, vector<string> &maze){

    int n = maze.size();
    int m = maze[0].length();

    int nx, ny;
    for(int t = 0; t < currCommand.length(); t++){
      auto d = dir[currCommand[t]];
      nx = x + d[0];
      ny = y + d[1];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        continue; // Robot hits the outer wall boundary, stays in the same cell
      }
      if(maze[nx][ny] == '#'){
        continue; // Robot hits an internal wall, stays in the same cell
      }
      if(maze[nx][ny] == 'E'){
        // If the robot crosses the exit cell at any point, it escapes immediately!
        return {false, {}}; 
      }
      x = nx;
      y = ny;
    }

    return {true, {x, y}};
  }

  void populateNextCommandTraverse(int x, int y, vector<string> &maze){

    queue<pair<vector<int>, string>> q;
    int n = maze.size();
    int m = maze[0].length();
    q.push({{x, y}, ""});

    vector<vector<int>> local_vis(n, vector<int>(m, 0)); // FIX: Match dimensions to (n, m) safely
    int nx, ny;

    while(!q.empty()){
      auto t = q.front();
      q.pop();

      if(local_vis[t.first[0]][t.first[1]]){
        continue;
      }

      local_vis[t.first[0]][t.first[1]] = 1;

      if(maze[t.first[0]][t.first[1]] == 'E'){
        currCommand += t.second;
        return;
      }

      string comm = t.second;

      for(auto d: dir){
        // FIX: Changed from 'x' and 'y' to 't.first[0]' and 't.first[1]'
        // Your original code was calculating neighbors relative to the original start cell every loop,
        // which trapped the BFS in place. Now it moves forward using the popped queue node.
        nx = t.first[0] + d.second[0]; 
        ny = t.first[1] + d.second[1]; 

        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
          continue; // FIX: Simply skip out-of-bound spaces during pathfinding exploration
        }

        if(maze[nx][ny] == '#'){
          continue; // FIX: Simply skip wall spaces when looking for an open path to the exit
        }
        q.push({{nx, ny}, comm + d.first});
      }
    }
  }

  string exitCommand(vector<string> maze){

    int i, j;
    int n = maze.size();
    int m = maze[0].length();

    vis.assign(n, vector<int>(m, 0)); // FIX: Match dimensions to (n, m) safely

    for(i = 0; i < n; i++){
      for(j = 0; j < m; j++){
        if(maze[i][j] != '#'){
          auto res = prevCommandTraverse(i, j, maze);
          // FIX: Removed `!vis[i][j]` check. Because appending commands moves *all* hypothetical positions, 
          // a simple static grid visitation map would miss recalculating robots that shifted back onto old starting cells.
          if(res.first){ 
            populateNextCommandTraverse(res.second[0], res.second[1], maze);
          }
        }
      }
    }

    return currCommand;
  }
};
