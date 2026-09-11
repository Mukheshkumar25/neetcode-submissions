class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = nums[0];
        int l =0 ;
        int r = nums.size()-1;
        while(l<=r)
        {
            if(nums[l] <= nums[r])
            {
                mini = min(mini,nums[l]);
                break;
            }
            int m = (l + r) >> 1;
            mini=min(mini,nums[m]);
            if(nums[m] >= nums[l])
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return mini;
    }
};
