class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
    for(auto &f : flights)
        adj[f[0]].push_back({f[1], f[2]}); // directed graph

    using T = pair<int, pair<int,int>>; // {cost, {node, stops}}
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, {src, 0}});

    while(!pq.empty()) {
        auto [cost, info] = pq.top(); pq.pop();
        auto [u, stops] = info;

        if(u == dst) return cost;
        if(stops > k) continue;

        for(auto [v, w] : adj[u])
            pq.push({cost + w, {v, stops + 1}});
    }

    return -1; 
    }
};
