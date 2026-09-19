class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int pro = INT_MIN;
        for(int i :prices)
        {
            mini = min(mini,i);
            pro = max(pro,i - mini);
        }
        return pro;
    }
};
