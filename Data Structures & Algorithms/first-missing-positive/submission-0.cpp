class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = 0;
        unordered_map<int,int>freq;
        for(int i:nums)
        {
            maxi = max(maxi,i);
            freq[i]++;
        }
        bool found = false;
        for(int i=1;i<=maxi;i++)
        {
            if(freq[i] == 0)
            {
                return i;
            }
        }
        return maxi+1;
        
    }
};