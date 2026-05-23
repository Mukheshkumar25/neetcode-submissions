
class Compare
{
    public:
    bool operator()(pair<int,int>a,pair<int,int>&b)
    {
        return a.second<b.second;
    }
};
class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i:nums)
        {
            freq[i]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
        for(auto[e,count]:freq)
        {
            pq.push({e,count});
        }
        vector<int>res;
        for(int i =0 ;i<k;i++)
        {
            auto top = pq.top();pq.pop();
            res.push_back(top.first);
        }
        return res;
    }
};
