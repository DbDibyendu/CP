

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
#include <shared_mutex> // Needed for Reader-Writer Locks
#include <mutex>
#endif

using namespace std;




bool commandValidate(vector<string> roads, string command){
  int i, j, k, l;
  int rLength = roads[0].length();
  int initFuel = 50;

  i = 0; // Tracks longitudinal road position (column index)
  j = 1; // Tracks current lane (row index)
  k = 0; // Tracks command index string ticker

  while(i < rLength){
    // FIX: Read the actual character from the command string instead of raw integer
    char com = command[k % 10]; 

    if(initFuel <= 0) return false;

    // FIX: Swapped index order from roads[i][j] to roads[j][i] 
    // roads has 3 rows (lanes) and rLength columns (positions)
    if(com == 'D'){
      i++;
      initFuel--;
      if(i < rLength && roads[j][i] == 'O') return false;
    }else if(com == 'L'){
      j--;
      initFuel--;
      if(j < 0 || roads[j][i] == 'O') return false;
    }else if(com == 'R'){
      j++;
      initFuel--;
      if(j > 2 || roads[j][i] == 'O') return false;
    }else{ // 'F'
      if(roads[j][i] == 'O') return false;
      // Refueling takes 1 unit of time but doesn't consume fuel
      if(roads[j][i] == 'F'){
         initFuel = min(100, initFuel + 50); // Cap tank capacity at 100
      }
    }
    k++;
  }

  return true;
}


// SO BFS was better here because we are able to early prune the conditions
// If taken the Recur approach, we would have to generate all the elements first and then try
string findCommandForRoad(vector<string> roads){


  int start = 1;
  int roadLength = roads[0].length(); // greater than 10

  // run bfs to find the best path

  if(roads[1][0] == 'O') return "";

  queue<pair<vector<int>, string>> q;
  // x, y 
  q.push({{1, 0}, ""}); // starting fuel


  int i, j, k;
  // boxed bfs 
  // command 10 length creation
  for(i=0; i<10;i++){

    int qSize = q.size();

    for(k=0;k<qSize;k++){ // increamentally 4^10, at each iteration
    auto top = q.front();
    q.pop();

    for(j=0;j<4;j++){

      int newPos;
      string upCom;
      if(j == 0){
        newPos = top.first[1] + 1;
        if(roads[top.first[0]][newPos] != 'O'){
          upCom = top.second + 'D';
          q.push({{top.first[0], newPos}, upCom});
        }
      }else if(j == 1){
        newPos = top.first[0] - 1;
        if(newPos >=0 && roads[newPos][top.first[1]]){
          upCom = top.second + 'L';
          q.push({{newPos, top.first[1]}, upCom});
        }
      }else if(j == 2){
        newPos = top.first[0] + 1;
        if(newPos <3 && roads[newPos][top.first[1]]){
          upCom = top.second + 'R';
          q.push({{newPos, top.first[1]}, upCom});
        }
      }else{
        // try fueling irrespective
          upCom = top.second + 'F';
          q.push({{top.first[0], top.first[1]}, upCom});
      }
    }
    }
  }

  // worst case -> (3^10 ~ 9^5) commands

  // modify this further to run d from 10 - 1. Early pruning
  // Check if path exists for d=10, 9 ... if yes then early return. Instead of generating all paths
  while (!q.empty()) {
    auto qEl = q.front(); // Look at the front element
    q.pop();              // Remove it from the original queue
    
    if(qEl.first[1] == 0) continue; // command didn't move

    if (qEl.first[0] == 1) {  // early pruning
        
      if(commandValidate(roads, qEl.second)){
        // to get minimum path, just return value of steps and maintain min
        return qEl.second;
      }
    }
  }

  // TC : O(3^10*N*10)
  // Space: O(3^10*10) storing the commands in queue
  return "";
}
