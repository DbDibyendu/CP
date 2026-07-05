#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Server {
  string type;
  int number;
};

class Tracker {
private:
  unordered_map<string, priority_queue<int, vector<int>, greater<int>>> serverGaps;
  // Maps server type -> ordered map of active numbers
  unordered_map<string, map<int, int>> server;

  pair<string, int> parse(string s) {
    auto dashPos = s.find('-');
    if (dashPos == string::npos) return {"", 0};

    string type = s.substr(0, dashPos); 
    string numS = s.substr(dashPos + 1); 

    return {type, stoi(numS)};
  }

public:
  void init(vector<string> inventory) {
    for (const string& i : inventory) {
      auto [type, number] = parse(i);
      if (!type.empty()) {
        server[type][number] = 1; // Mark as an active server
      }
    }

    // Identify gaps up to the largest active element
    for (auto& s : server) {
      string type = s.first;
      if (s.second.empty()) continue;

      // rbegin() gives us an iterator to the largest key safely
      int maxEl = s.second.rbegin()->first; 
      
      for (int j = 1; j <= maxEl; j++) {
        if (s.second.find(j) == s.second.end()) {
          serverGaps[type].push(j); // Missing number is pushed as a gap
        }
      }
    }
  }

  string allocate(string type) {
    int assignedNum = 0;

    // 🛠️ FIX: Changed from 'while' to 'if', and verified the queue isn't empty
    if (serverGaps.find(type) != serverGaps.end() && !serverGaps[type].empty()) {
      assignedNum = serverGaps[type].top();
      serverGaps[type].pop();
    }

    // If no gaps were available, generate the next incremental number
    if (assignedNum == 0) {
      // 🛠️ FIX: Corrected flipped conditions and replaced end() with rbegin()
      if (server[type].empty()) {
        assignedNum = 1;
      } else {
        assignedNum = server[type].rbegin()->first + 1;
      }
    }

    // Register this server as active so the max-element tracking stays accurate
    server[type][assignedNum] = 1;

    return type + "-" + to_string(assignedNum);
  }

  void deallocate(string s) {
    auto [type, number] = parse(s);
    if (!type.empty()) {
      serverGaps[type].push(number); // Return the number to the available pool
      server[type].erase(number);     // Remove it from the active map pool
    }
  }
};


// you don't require map here 
class TrackerV2{
private:
  // Tracks deallocated holes (Min-Heap)
  unordered_map<string, priority_queue<int, vector<int>, greater<int>>> serverGaps;
  
  // Tracks the absolute highest number handed out + 1 (Simple counter!)
  unordered_map<string, int> nextFreshNumber;


  // added some run_time errors
  pair<string, int> parse(string s) {
    auto dashPos = s.find('-');
    if (dashPos == string::npos || dashPos == 0 || dashPos == s.length() - 1) {
        throw runtime_error("Malformed server name format: '" + s + "'. Expected {type}-{number}.");
    }

    string type = s.substr(0, dashPos); 
    string numS = s.substr(dashPos + 1); 

    // indication of production ready code
    // Need to handle such edge cases properly
    try {
        int num = stoi(numS);
        if (num <= 0) throw runtime_error("Server number must be positive.");
        return {type, num};
    } 
    catch (const invalid_argument& e) {
        throw runtime_error("Invalid number format in '" + s + "'.");
    } 
    catch (const out_of_range& e) {
        throw runtime_error("Server number out of range in '" + s + "'.");
    }
  }

public:
  void init(vector<string> inventory) {
    // 1. First pass: Find the absolute maximum number present for each type
    for (const string& i : inventory) {
      auto [type, number] = parse(i);
      if (!type.empty()) {
        nextFreshNumber[type] = max(nextFreshNumber[type], number + 1);
      }
    }

    // 2. Second pass: Find gaps below that maximum number
    // We can use a temporary hash set to see what's missing up to the max seen
    unordered_map<string, unordered_set<int>> presentNums;
    for (const string& i : inventory) {
      auto [type, number] = parse(i);
      if (!type.empty()) presentNums[type].insert(number);
    }

    for (auto& pair : nextFreshNumber) {
      string type = pair.first;
      int maxNum = pair.second; // This is max seen + 1
      
      for (int j = 1; j < maxNum; j++) {

        // presentNums just required at the start init
        if (presentNums[type].find(j) == presentNums[type].end()) {
          serverGaps[type].push(j);
        }
      }
    }
  }

  string allocate(string type) {
    int assignedNum = 0;

    // Rule 1: Always check for a recycled gap first
    if (!serverGaps[type].empty()) {
      assignedNum = serverGaps[type].top();
      serverGaps[type].pop();
    } 
    // Rule 2: If no gaps, take a brand new number from our baseline counter
    else {
      if (nextFreshNumber.find(type) == nextFreshNumber.end()) {
        nextFreshNumber[type] = 1; // Start at 1 for completely new server types
      }
      assignedNum = nextFreshNumber[type]++;
    }

    return type + "-" + to_string(assignedNum);
  }

  void deallocate(string s) {
    auto [type, number] = parse(s);
    if (!type.empty()) {
      serverGaps[type].push(number); // O(log G) - just drop it in the heap pool!
    }
  }
};
