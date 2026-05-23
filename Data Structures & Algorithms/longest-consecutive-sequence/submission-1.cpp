class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int mini =INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int>exist;
        for(int i:nums)
        {
            mini = min(mini,i);
            maxi = max(maxi,i);
            exist.insert(i);
        }
        int count = 0;
        int maxcount = 0;
        for(int i = mini;i<=maxi;i++)
        {
            if(exist.count(i))
            {
                count++;
                maxcount = max(maxcount,count);
            }
            else
            {
                count = 0;
            }
        }
        return maxcount;
    }
};
