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


struct MenuItem {
  int id;
  string name;
  string icon;
  vector<MenuItem> children;
  bool isExempt;
};

class Menu {

  // DFS better approach for this prblm for lower space complexity and ease of breaking 
  // a prblm down into a recursive small prblm statement
  // TC: O(Menu Items)
  // SC: O(Menu Items)
// Helper to evaluate a single list of MenuItems
    bool dfs(MenuItem& parent) {
        bool ans = true;
        unordered_set<string> seen_icons;
        int icon_count = 0;

        // 1. Process current menu level
        for (auto& child : parent.children) {
            if (child.icon != "") {
                icon_count++;
                
                // Follow Up 1: Check for duplicates within this menu
                if (!parent.isExempt && seen_icons.count(child.icon)) {
                    return false;
                }
                seen_icons.insert(child.icon);
            }
        }

        // Follow Up 2 & 3: Consistency within this menu
        // It is valid if ALL items have icons, or NO items have icons.
        bool isConsistent = (icon_count == parent.children.size() || icon_count == 0);
        
        // Follow Up 4: If exempt, we ignore the consistency check for THIS level
        if (!parent.isExempt && !isConsistent) {
            return false; 
        }

        // 2. Recurse into submenus
        for (auto& child : parent.children) {
            // Only recurse if the child actually has its own submenus
            if (!child.children.empty()) {
                ans &= dfs(child);
            }
        }

        return ans;
    }

    bool checkAllMenuItems(vector<MenuItem> items) {
        MenuItem root; 
        root.isExempt = false; // Root is just a container, not exempt
        root.children = items;
        
        return dfs(root);
    }

  bool checkAllMenuBFS(vector<MenuItem> items){

    queue<pair<MenuItem,int>> q;
    unordered_map<pair<string,int>,int> same_level_icon;

    for(auto &i: items){
      q.push({i,0});
    }
    int total_items=0;
    // important
    while(!q.empty()){
      total_items++;
      auto [t, menu_id] = q.front();
      q.pop();

      if(t.icon != ""){
        pair<string,int> key = {t.icon, menu_id}; // duplicate check
      // follow up 1
        if(same_level_icon.count(key)) return false;
        same_level_icon[key]++;
      }

      int i=1;
      for(auto &v: t.children){ // all children belongs to same menu
        q.push({v, menu_id+i});
      }
      i++;
    }
    
    // follow up 2
    return (same_level_icon.count() == total_items);

  }

};
//=======================
