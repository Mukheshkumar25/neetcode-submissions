class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        cur_ele = -101
        idx = -1
        for i in nums:
            if cur_ele != i:
                idx+=1
                nums[idx] = i
                cur_ele = i

            
        return idx+1
        