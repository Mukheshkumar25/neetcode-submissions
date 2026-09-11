#define pi pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i:nums)
        {
            freq[i]++;
        }
        priority_queue<pi,vector<pi>>pq;
        for(auto[ele,count]:freq)
        {
            pq.push({count,ele});
        }
       vector<int>res;
       while(k>0 && !pq.empty())
       {
        auto[c,ele] = pq.top();pq.pop();
        res.push_back(ele);
        k--;
       }
       return res;
    }
};
