
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> lprod(n, 1), rprod(n, 1);
        vector<int> ans(n, 1);

        // Products of elements to the left
        for (int i = 1; i < n; i++) {
            lprod[i] = lprod[i - 1] * nums[i - 1];
        }

        // Products of elements to the right
        for (int i = n - 2; i >= 0; i--) {
            rprod[i] = rprod[i + 1] * nums[i + 1];
        }

        // Product except self
        for (int i = 0; i < n; i++) {
            ans[i] = lprod[i] * rprod[i];
        }

        return ans;
    }
};

