class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>>adjlist(n);
        queue<int>q;
        for(auto e :edges)
        {
            int u = e[0];
            int v = e[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int>visited(n,0);
        for(int  i =0 ;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
                count++;
                while(!q.empty())
                {
                    auto node = q.front();q.pop();
                    for(auto nei:adjlist[node])
                    {
                        if(!visited[nei])
                        {
                            visited[nei] = true;
                            q.push(nei);
                        }
                    }
                }
            }
        }
        return count;
    }
};
