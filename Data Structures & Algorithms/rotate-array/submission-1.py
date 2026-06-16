class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums.reverse()
        k = k % len(nums)
        nums[:k] = nums[0:k][::-1]
        nums[k:] = nums[k:][::-1]
        