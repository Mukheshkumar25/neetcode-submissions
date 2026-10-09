class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        unordered_map<int,int>freq;
        for(char c:s)
        {
            freq[c - 'a']++;
        }
        for(char c:t)
        {
            if(freq[c-'a'] <= 0)return false;
            freq[c - 'a']--;
        }
        return true;
    }
};
