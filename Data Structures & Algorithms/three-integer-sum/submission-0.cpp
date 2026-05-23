class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i =0 ;i<n-2;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int req = -1 * nums[i];
            int l = i+1;
            int r = n-1;
            while(l<n && r>=0 && l<r)
            {
                int sum = nums[l] + nums[r];
                if( sum == req)
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    while( l +1 <n && nums[l] == nums[l+1])l++;
                    while(r-1>=0 && nums[r] == nums[r-1])r--;
                    l++;
                    r--;
                }
                else if(sum < req)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i])i++;
        }
        return res;
    }
};
