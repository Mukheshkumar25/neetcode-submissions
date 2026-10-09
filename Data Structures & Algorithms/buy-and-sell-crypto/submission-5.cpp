class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi =0 ;
       int mini = prices[0];
       for(int i : prices)
       {
        mini = min(mini,i);
        maxi = max(maxi,i - mini);
       } 
       return maxi;
    }
};
