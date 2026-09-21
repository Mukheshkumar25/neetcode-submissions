class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>> q1, q2;

        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));

        // Left + Top borders
        for(int i = 0; i < n; i++)
        {
            q1.push({i, 0});
            vis1[i][0] = true;
        }

        for(int j = 0; j < m; j++)
        {
            q1.push({0, j});
            vis1[0][j] = true;
        }

        // Right + Bottom borders
        for(int i = 0; i < n; i++)
        {
            q2.push({i, m - 1});
            vis2[i][m - 1] = true;
        }

        for(int j = 0; j < m; j++)
        {
            q2.push({n - 1, j});
            vis2[n - 1][j] = true;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // BFS from Pacific
        while(!q1.empty())
        {
            auto [x, y] = q1.front();
            q1.pop();

            for(int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < m &&
                   !vis1[nx][ny] &&
                   heights[nx][ny] >= heights[x][y])
                {
                    vis1[nx][ny] = true;
                    q1.push({nx, ny});
                }
            }
        }

        // BFS from Atlantic
        while(!q2.empty())
        {
            auto [x, y] = q2.front();
            q2.pop();

            for(int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < m &&
                   !vis2[nx][ny] &&
                   heights[nx][ny] >= heights[x][y])
                {
                    vis2[nx][ny] = true;
                    q2.push({nx, ny});
                }
            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis1[i][j] && vis2[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};