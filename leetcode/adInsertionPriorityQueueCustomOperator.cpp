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

struct AdContext {
  string contentId;
  int score;
  int delay;
  int nextPossibleTime;
};


struct cmp{
  bool operator()(const AdContext &a, const AdContext &b){

    if(a.nextPossibleTime == b.nextPossibleTime){
      if(a.score == b.score){
        return a.contentId > b.contentId;
      }
      return a.score < b.score; // Higher score on top
    }
// "Should element a be pushed deeper down into the heap than element b?" , min Heap
    return a.nextPossibleTime > b.nextPossibleTime;
  }
};

// type, container, comparator : Priority queue syntax


class AdServer {
  
  // type, container, comparator, remember the format
  priority_queue<AdContext, vector<AdContext>, cmp> pq;
  string lastServedAd;
  int currTime;

  int N;
  public:
  AdServer(){
    lastServedAd = "";
    currTime = 0;
  }

  void insertAd(string contentId, int score, int delay){ // log(n)
    AdContext ad;
    ad.contentId = contentId;
    ad.score = score;
    ad.delay = delay;
    ad.nextPossibleTime = 0;

    pq.push(ad);
  }

  string getAd(){ // O(logN)

    if(pq.empty()) return "";
    if(pq.top().nextPossibleTime > currTime) {
      return ""; 
    }
    auto t = pq.top();
    pq.pop();
    
    t.nextPossibleTime = currTime + t.delay;
    t.score--;
    pq.push(t);
    currTime++;
    return t.contentId;
  }

};



// Sorting struct example operator
struct CompareAds {
    bool operator()(const AdContext& a, const AdContext& b) const {
        return a.score > b.score; // '>' means DESCENDING order (highest score first)
    }
};

int main() {
    vector<AdContext> ads = {{"ad1", 10}, {"ad2", 50}, {"ad3", 30}};

    // 2. Pass an INSTANCE of the struct by adding () at the end
    sort(ads.begin(), ads.end(), CompareAds()); 
    // ads is now: ad2 (50), ad3 (30), ad1 (10)
}



// follow up 2

// 🌟 SUPER SIMPLE COMPARATOR: No time tracking needed!
struct PureScoreCmp {
  bool operator()(const AdContext &a, const AdContext &b) const {
    if (a.score == b.score) {
      return a.contentId > b.contentId; // Deterministic tie-breaker
    }
    return a.score < b.score; // Higher score bubbles to the top (Max-Heap)
  }
};

class AdvancedAdServer {
private:
  priority_queue<AdContext, vector<AdContext>, PureScoreCmp> eligiblePQ;
  
  queue<AdContext> cooldownFIFO; 
  
  int N; // The number of past ads that cannot be served

public:
  AdvancedAdServer(int historyLimit) {
    N = historyLimit;
  }

  // Time Complexity: O(log M) where M is the number of active eligible ads
  // saved time complexity here as M < N
  void insertAd(string contentId, int score) {
    eligiblePQ.push({contentId, score});
  }

  // Time Complexity: Strictly O(log M) worst-case
  string getAd() {
    if (eligiblePQ.empty()) return "";

    auto servedAd = eligiblePQ.top();
    eligiblePQ.pop();

    servedAd.score--;

    cooldownFIFO.push(servedAd);

    // 4. If our cooldown window exceeds size N, the oldest ad is liberated 
    // and goes back into the active pool
    if (cooldownFIFO.size() > N) {
      auto liberatedAd = cooldownFIFO.front();
      cooldownFIFO.pop();
      eligiblePQ.push(liberatedAd);
    }

    return servedAd.contentId;
  }
};
