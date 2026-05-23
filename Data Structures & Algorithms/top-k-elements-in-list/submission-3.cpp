class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
    for (int i : nums)
    {
        freq[i]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (auto [d, count] : freq)
    {
        pq.push({count, d});
        while(pq.size() >k)
        {
            pq.pop();
        }
    }
    auto temp = pq;

    cout << "Priority Queue contents:\n";

    while (!temp.empty())
    {
        auto [count, num] = temp.top();

        cout << "Number: " << num
             << ", Frequency: " << count << endl;

        temp.pop();
    }
        vector<int>res;
        while(!pq.empty())
        {
            auto [co,val] = pq.top();pq.pop();
            res.push_back(val);
        }
        return res;
    }
};
