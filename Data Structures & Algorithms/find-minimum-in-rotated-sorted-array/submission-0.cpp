class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l =0 ;
        int h = n-1;
        int res  = nums[0];
        while(l<=h)
        {
             if (nums[l] <= nums[h]) {
                res = min(res, nums[l]);
                break;
            }
            int m = l + (h - l) / 2;
            res = min(res, nums[m]);
            if(nums[m] >= nums[l])
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
        }
        return res;
    }
};