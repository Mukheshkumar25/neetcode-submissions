class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi =0 ;
        int mini =INT_MAX;
        for(int i:prices)
        {
            mini = min(i,mini);
            maxi = max(maxi ,i - mini);
        }
        return maxi;
    }
};
