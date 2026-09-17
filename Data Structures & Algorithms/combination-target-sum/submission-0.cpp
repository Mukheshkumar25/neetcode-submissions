class Solution {
public:
    void solve(int idx,vector<int>&nums,int t,vector<vector<int>>&res,vector<int>&path)
    {
        if(t == 0)
        {
            res.push_back(path);
            return;
        }
        if(idx>=nums.size())
        {
            return;
        }
        //pick
        if(nums[idx] <= t)
        {
            path.push_back(nums[idx]);
            solve(idx,nums,t - nums[idx],res,path);
            path.pop_back();
        }
        solve(idx+1,nums,t,res,path);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>path;
        solve(0,nums,target,res,path);
        return res; 
    }
};
