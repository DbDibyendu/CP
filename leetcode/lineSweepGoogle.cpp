

// Question: https://leetcode.com/discuss/post/5670972/google-l4-onsite-by-anonymous_user-xnj8/
//


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


struct Range {
    string person;
    int l;
    int r;
};

struct Output {
    unordered_set<string> persons;
    int l, r;
};

class Solution{
  vector<int> nums;
  // line sweep algo
  vector<Output> returnSequenceOfUsers(vector<Range> ranges) {
        int n = ranges.size();
        if (n == 0) return {};
        int i,j;

        map<int, vector<pair<int,string>>> uniq_points;
		    for(i=0;i<n;i++){
          uniq_points[ranges[i].l].push_back({1, ranges[i].person});
          uniq_points[ranges[i].r].push_back({-1, ranges[i].person});
		    }

        int prev = -1;

        vector<Output> result;

        unordered_set<string> active_persons;

        for(auto &u : uniq_points){
          // firstly range management

          int curr = u.first;

          if(prev != -1 && curr > prev && active_persons.size() > 0){
            Output curr_ans;
            curr_ans.l = prev;
            curr_ans.r = curr;
            curr_ans.persons = active_persons;
            result.push_back(curr_ans);
          }
          for(auto &a: u.second){
            if(a.first == 1){
              active_persons.insert(a.second);
            }else{
              active_persons.erase(a.second);
            }
          }

          prev = curr;
        }


        // TC: O(NlogN)
        // SC: O(N)
        return result;
  }
};

