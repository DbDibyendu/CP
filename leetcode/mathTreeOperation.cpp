
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
//
// ( a op1 b) op2 c // 2*2
//
// a op1 (b op2 c)// 2*2
//                //
//                // O(L), O(L)
//                //
//   (2 3) * (4 5)
//
//   solve(l, r)
//   1 2 | 3 4 5 -> + or *
//
//   solve(2,5)
//
//   = leftSub * rightSubs *2

struct Result {
  int value;
  string expr;
};

class Solution{
  vector<int> nums;

  map<pair<int,int>, vector<Result>> memo;

  vector<Result> dfs(int l, int r){

    if(memo.count({l,r})){
      return memo[{l,r}];
    }
    vector<Result> ans;
    // base case
    if(l==r){
      ans.push_back({nums[l], to_string(nums[l])});
      return memo[{l,r}] = ans;
    }

    // l =0, r = 2, split , concatenate
    for(int k=l ; k<r;k++){
      auto left = dfs(l, k);// 0 1 -> 2*3 or 2+3
      auto right = dfs(k+1, r); // 2 2 -> 4

      for(auto &L : left){
        for(auto &R: right){

          // +
          ans.push_back({L.value + R.value, "(" + L.expr + "+" + R.expr + ")"});
          ans.push_back({L.value*R.value, "(" + L.expr + "*" + R.expr + ")"});
        }
      }
    }

    return memo[{l,r}] = ans;
    // TIme :O(Exponential -> all unique expression possible) ~ O(2^n-1)
    // Space : O(number of generated expression)
  }

  string solvePartition(vector<int> &partition, int target){

    nums = partition;
    memo.clear();
    auto all = dfs(0, nums.size()-1);

    for(auto a: all){
      if(a.value == target){
        return a.expr;
      }
    }
    return "";
  }

  bool generatePartitions(int idx, vector<int>&digits, vector<int> &current, int currentNum, int target, string &ans){
    
    // base case
    if(idx == digits.size()){
      current.push_back(currentNum);

      string res = solvePartition(current, target);
      if(res == "") return false;
      current.pop_back();
      if(!res.empty()){
        ans = res;
        return true;
      }
      return false;
    }

    // option 1: concate current digit

    if(generatePartitions(idx+1, digits, current, currentNum*10+digits[idx], target, ans))
      return true;

    current.push_back(currentNum);
    // split here
    if(generatePartitions(idx+1, digits, current, digits[idx], target, ans))
      return true;

    current.pop_back(); // back track

    return false;
  }

  string validExpression(vector<int> &digits, int target){
    nums = digits;

    auto all = dfs(0, nums.size()-1);

    vector<int> partition;
    string answer = "";
    if(generatePartitions(1, digits, partition, digits[0], target, answer)){
      return answer;
    }

    // Time : O(2^N * Catalan) 
    // Catalan -> 2nCn
    return "No solution";
  }
};

// 2 3 4 = 20
