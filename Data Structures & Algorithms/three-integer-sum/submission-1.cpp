class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i =0 ;i<nums.size();i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int sum = nums[l] + nums[r] + nums[i];
                if( sum == 0 && i!=l && i != r)
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l+1 < nums.size() && nums[l+1] == nums[l])
                    {
                        l++;
                    }
                    while(r-1 >=i&& nums[r-1] == nums[r])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
                else if(sum <0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1])i++;
        }
        return res;
    }
};
