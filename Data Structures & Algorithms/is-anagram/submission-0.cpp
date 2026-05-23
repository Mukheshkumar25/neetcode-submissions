class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>freq1,freq2;
        for(char c:s)
        {
            freq1[c - 'a']++;
        }
        for(char c:t)
        {
            freq2[c - 'a']++;
        }
        return freq1 == freq2;
    }
};
