class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});  // frequency first
            if (pq.size() > k) pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second); // extract number
            pq.pop();
        }

        return res;
    }
};