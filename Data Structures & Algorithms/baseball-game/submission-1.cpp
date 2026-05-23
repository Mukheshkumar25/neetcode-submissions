class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>nums;
        for(string  i :operations)
        {
            if(i == "+")
            {
                nums.push_back(nums[nums.size()-1] + nums[nums.size()-2]);
            }
            else if(i=="D")
            {
                nums.push_back(nums.back()*2);
            }
            else if(i=="C")
            {
                nums.pop_back();
            }
            else
            {
                nums.push_back(stoi(i));
            }
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};