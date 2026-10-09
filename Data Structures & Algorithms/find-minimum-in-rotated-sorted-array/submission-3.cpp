class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int l =0 ;
        int h = n-1;
        while(l<=h)
        {
            if(nums[l] < nums[h])
            {
                mini = min(mini,nums[l]);
                return mini;
            }
            int m = (l + h) >>1;
            mini = min(mini,nums[m]);
            if(nums[m] >= nums[l])
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
        }
        return mini;
    }
};
