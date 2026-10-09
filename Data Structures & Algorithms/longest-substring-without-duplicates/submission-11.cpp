class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1)return 1;
        unordered_map<char,int>idx;
        int l =0 ;
        int maxlen = 0;
        for(int i =0 ;i<s.length();i++)
        {
            char c = s[i];
            if(idx.find(c) != idx.end())
            {
                l = max(l,idx[c] + 1);
            }
            maxlen = max(maxlen,i - l+1);
            idx[c] = i;
        }
        return maxlen;
    }
};
