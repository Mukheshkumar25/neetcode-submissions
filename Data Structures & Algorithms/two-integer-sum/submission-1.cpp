class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>indices;
        int n = nums.size();
        for(int i =0 ;i<n;i++)
        {
            int req = target - nums[i];
            if(indices.find(req) != indices.end())
            {
                return{indices[req],i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
