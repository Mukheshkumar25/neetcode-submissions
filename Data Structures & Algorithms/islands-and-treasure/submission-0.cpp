class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int INF = 2147483647;
        queue<pair<int,int>> q;


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                } else if(grid[i][j] != -1) {
                    grid[i][j] = INF;
                }
            }
        }

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto d: directions) {
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != -1) {
                    if(grid[nx][ny] > grid[x][y] + 1) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};
