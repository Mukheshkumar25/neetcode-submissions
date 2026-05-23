class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>ind;
        int maxlen =0 ;
        int left =0 ;
        for(int i =0 ;i<s.length() ;i++)
        {
            if(ind.find(s[i]) != ind.end())
            {

                left = max(left,ind[s[i]] + 1);
            }
            ind[s[i]] = i;
            maxlen = max(maxlen,i-left+1);
                    }
        return maxlen;
    }
};
