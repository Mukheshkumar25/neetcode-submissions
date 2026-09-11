class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int i : nums)
        {
            if(seen.find(i) == seen.end())
            {
                seen.insert(i);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};