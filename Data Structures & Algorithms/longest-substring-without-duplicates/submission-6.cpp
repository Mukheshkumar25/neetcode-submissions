class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        int maxi = 1;
        unordered_map<char,int>idx;
        int l = 0;
        for(int i =0 ;i<s.length();i++)
        {
            if(idx.find(s[i]) != idx.end())
            {
                l = max(idx[s[i]] + 1,l);
            }
            maxi = max(maxi,i - l +1);
            idx[s[i]] = i; 
        }
        return maxi;
    }
};
