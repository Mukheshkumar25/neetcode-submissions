class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> idx_sum;
        idx_sum[0] = 1;   
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int req = sum - k;
            if(idx_sum.find(req) != idx_sum.end()) {
                count += idx_sum[req];
            }
            idx_sum[sum]++;
        }
        return count;
    }
};
