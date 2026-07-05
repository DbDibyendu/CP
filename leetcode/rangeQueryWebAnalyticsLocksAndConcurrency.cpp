

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

class FenwickTree {

  public:
  unordered_map<int, double> sum;
  unordered_map<int,int> count;
  const long long MAX_LIMIT = 2000000000LL;


  void updateSum(int index, double delta){

    while(index < MAX_LIMIT){
      sum[index] += delta;
      index += (index & -index);
    }
  }

  double querySum(int index){

    double totalS = 0.0;

    while(index >0){
      totalS += sum[index];
      index -= (index & -index); // subtract lowest set bit
    }

    return totalS;
  }

  void updateCount(int index, int delta){

    while(index < MAX_LIMIT){
      count[index] += delta;
      index += (index & -index);
    }
  }

  int queryCount(int index){

    int totalS = 0.0;

    while(index >0){
      totalS += count[index];
      index -= (index & -index); // subtract lowest set bit
    }

    return totalS;
  }
 
};

// it's all implementation

class WebAnalytics{

  map<int,int> mp;
  double minScore, maxScore;
  FenwickTree *tree; 
  WebAnalytics(){

    tree = new FenwickTree();
    minScore = 1e18;
    maxScore = -1e18;
  }
  std::shared_mutex rw_mutex;

  void update(int ts, double score){
    mp[ts] = score; // log(n)
    
    unique_lock<shared_mutex> lock(rw_mutex);
    tree->updateSum(ts, score); // log(ts)
    minScore = min(minScore, score);
    maxScore = max(maxScore, score);

  }

  double currQualityScore(){
    if(mp.size() == 0) return 0;
    return mp.rbegin()->second; 
  }

  vector<double> minMaxScore(){
    return {minScore, maxScore};
  }

  double averageScore(int start, int end){
    // store count and sum in segment tree
    // do it via maps only

    if(mp.empty()) return 0.0;

    auto it = mp.lower_bound(start);

    double sum=0;
    int count=0;
    while(it != mp.end() && it->first <= end){
      count++;
      sum+= it->second;
      it++;
    }

    return sum/count; // O(logN + K)
  }


  double averageScoreV2(int start, int end){
    // store count and sum in segment tree
    // do it via maps only

    if(start  > end) return 0;
    double s_sum = tree->querySum(start-1);
    double e_sum = tree->querySum(end);

    double t_sum = e_sum - s_sum;

    double s_count= tree->queryCount(start-1); // log(end)
    double e_count= tree->queryCount(end);

    double t_count= e_sum - s_sum;

    if(t_count == 0) return 0;

    return (t_sum/t_count);
  }

};


// 🔒 C++ SYNCHRONIZATION: UNIQUE_LOCK VS. SHARED_LOCK CODESHEET : READER_WRITER lock

/* 📑 THE MULTI-THREADING DILEMMA
 * Standard C++ containers (std::map, std::vector) allow concurrent reads,
 * but crash immediately if a write happens simultaneously with any read or write.
 * * To solve this efficiently, we pair a `std::shared_mutex` with two different lock wrappers:
 */

/* 1️⃣ std::unique_lock<std::shared_mutex> (THE EXCLUSIVE WRITER)
 * -------------------------------------------------------------------------
 * • Behavior:   Blocks EVERYONE. No other readers, no other writers.
 * • When to use: Inside WRITE operations (Insert, Update, Delete, Clear).
 * • Impact:     Guarantees that the thread has 100% isolated ownership to modify
 * the data structure safely without background rehashes or memory shifts.
 *
 * 2️⃣ std::shared_lock<std::shared_mutex> (THE CONCURRENT READER)
 * -------------------------------------------------------------------------
 * • Behavior:   Allows other readers in, but blocks writers.
 * • When to use: Inside READ operations (Querying sums, averages, min/max lookups).
 * • Impact:     Prevents application crashes caused by a writer modifying memory 
 * underneath a reader, while allowing infinite readers to fly 
 * through the code concurrently at maximum performance.
 *
 *
 * Always think this direction when adding locks
 * Write -> Write (parallel)
 * Read -> Read
 * Read -> Write
 * Write -> Read
 */
