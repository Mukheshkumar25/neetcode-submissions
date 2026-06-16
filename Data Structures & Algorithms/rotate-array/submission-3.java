class Solution {
    public int[] reverse(int []nums,int l,int r)
    {
        while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;

        l++;
        r--;
    }
    return nums;
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        nums = reverse(nums,0,n-1);
        nums = reverse(nums,0,k-1);
        nums = reverse(nums,k,n-1);
    }
}