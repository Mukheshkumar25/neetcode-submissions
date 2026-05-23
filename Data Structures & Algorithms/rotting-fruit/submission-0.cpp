class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        // Count fresh oranges and enqueue initially rotten ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }

        if(fresh == 0) return 0;  // No fresh oranges

        int time = 0;

        while(!q.empty()) {
            int size = q.size();
            bool rottedThisRound = false;
            for(int i = 0; i < size; i++) {
                auto [x,y] = q.front(); q.pop();
                for(auto d: dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                        rottedThisRound = true;
                    }
                }
            }
            if(rottedThisRound) time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
