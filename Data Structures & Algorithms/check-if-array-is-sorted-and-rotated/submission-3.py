class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        count =0 
        for i in range(n-1):
            if nums[i] > nums[i+1]:
                count +=1
        if nums[0] < nums[n-1]:
            count+=1
        return count<2

        