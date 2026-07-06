#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
vector<vector<bool>> vis; 
vector<int> ans;

// simple dp[x][y] doesn't work here as we also need to save the visited path context as a dp state
int dfs(int x, int y, int parVal, vector<vector<int>> &matrix, vector<int> &current_path){
  int n = matrix.size();
  int m = matrix[0].size();
  
  vector<int> dx = {0, 0, 1, -1};
  vector<int> dy = {1, -1, 0, 0};

  vis[x][y] = true; 
  current_path.push_back(matrix[x][y]); 

  // Capture the global high-score path dynamically
  if (current_path.size() > ans.size()) {
    ans = current_path;
  }

  int max_downstream = 0; 
  for(int d =0;d<4;d++){
    int nx = x + dx[d];
    int ny = y + dy[d];

    if(nx < 0 || nx>=n || ny<0 || ny>=m) continue;
    if(vis[nx][ny]) continue; 

    if(matrix[nx][ny] > matrix[x][y] && matrix[nx][ny] > parVal) continue;
    
    // 🛠️ Pass the references forward into the recursion
    max_downstream = max(max_downstream, 1 + dfs(nx, ny, matrix[x][y], matrix, current_path));
  }

  current_path.pop_back(); // Backtrack local state step cleanly
  vis[x][y] = false; 
  return max_downstream;
}

int jumpingPath(vector<vector<int>> matrix){
  int n = matrix.size();
  if(n == 0) return 0;
  int m = matrix[0].size();

  dp.assign(n+1, vector<int>(m+1, -1));
  vis.assign(n+1, vector<bool>(m+1, false)); 
  
  vector<int> current_path; 

  int i,j;
  int max_path = 0;
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      vis.assign(n+1, vector<bool>(m+1, false)); 
      
      // 🛠️ Pass the tracking arrays down into the root call
      dp[i][j] = dfs(i, j, 1e9, matrix, current_path);
      max_path = max(dp[i][j], max_path);
    }
  }

  // Outputs the tracked array seamlessly
  for(auto a: ans){
    cout << a << endl;
  }
  
  return max_path;
}


// optimisation
map<tuple<int,int,int>, int> dp2;

vector<int> current_path; 

int dfs2(int currInd, int parInd, int vis_mask, vector<vector<int>> &matrix){
  int n = matrix.size();
  int m = matrix[0].size();
  
  // 🛠️ FIX: Standard 1D to 2D conversion using column stride 'm'
  int x = currInd / m;
  int y = currInd % m;

  // 🛠️ FIX: Correct C++ syntax for querying a map using a tuple key
  auto state = make_tuple(currInd, parInd, vis_mask);
  if(dp2.find(state) != dp2.end()){
    return dp2[state];
  }

  // Record path footprint live
  current_path.push_back(matrix[x][y]);
  if(current_path.size() > ans.size()){
    ans = current_path;
  }

  vector<int> dx = {0, 0, 1, -1};
  vector<int> dy = {1, -1, 0, 0};

  int max_downstream = 0; 

  for(int d = 0; d < 4; d++){
    int nx = x + dx[d];
    int ny = y + dy[d];
    int newInd = nx * m + ny; // 🛠️ FIX: Stride is 'm'

    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(vis_mask & (1 << newInd)) continue;
    
    // 🛠️ FIX: Handle height rules, managing the -1 (no parent) scenario safely
    if (parInd == -1) {
      if (matrix[nx][ny] > matrix[x][y]) continue;
    } else {
      int px = parInd / m;
      int py = parInd % m;
      if (matrix[nx][ny] > matrix[x][y] && matrix[nx][ny] > matrix[px][py]) continue;
    }
    
    // 🛠️ FIX: Pass 'vis_mask | (1 << newInd)' inline to avoid leaking state to other directions
    max_downstream = max(max_downstream, 1 + dfs2(newInd, currInd, vis_mask | (1 << newInd), matrix));
  }

  current_path.pop_back(); // Backtrack path trace
  return dp2[state] = max_downstream;
}

int jumpingPathV2(vector<vector<int>> matrix){
  int n = matrix.size();
  if(n == 0) return 0;
  int m = matrix[0].size();

  // Reset global states fresh for this calculation run
  dp2.clear(); 
  ans.clear();
  current_path.clear();

  int i, j;
  int max_path = 0;
  
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      
      int index = i * m + j; // 🛠️ FIX: Indexing matches column layout stride. Always check j<m, hence multipley by m
      
      // 🛠️ FIX: Seed with parent -1, and mark the starting node directly inside the initial mask
      int path_len = 1 + dfs2(index, -1, (1 << index), matrix);
      max_path = max(path_len, max_path);
    }
  }

  // Prints out the captured high-scoring path perfectly
  for(auto a: ans){
    cout << a << endl;
  }
  
  // time : O((M*N)*(M*N)*(2)^(M*N))
  return max_path;
}
