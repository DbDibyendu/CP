
class Solution
{

public:
    int n, m;
    void dfs(int x, int y, int n, int m, vector<pair<int, int>> &X, int (&visited)[305][305],vector<vector<char>> &grid)
    {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        visited[x][y] = 1;
        int i;
        for (i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m)
                if (visited[tx][ty] == 0 && grid[tx][ty]=='1')
                {
                    cout<<tx<<" "<<ty<<endl;
                    dfs(tx, ty, n, m, X, visited,grid);
                }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int i, j;
        n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> X;
        int visited[305][305] = {0};
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    X.push_back({i, j});
                }
            }
        }
        int ans = 0;
        for (auto x : X)
        {
            int a = x.first, b = x.second;
            if (visited[a][b] == 0)
            {
                cout<<a<<b<<endl;
                dfs(a, b, n, m, X, visited,grid);
                ans++;
            }
        }
        return ans;
    }
};