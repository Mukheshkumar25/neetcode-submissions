class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>idx;
        for(int i =0 ;i<nums.size();i++)
        {
            int req = target - nums[i];
            if(idx.find(req)!=idx.end() && idx[req] != i)
            {
                return{idx[req],i};
            }
            idx[nums[i]] = i;
        }
        return{-1};
    }
};
