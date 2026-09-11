class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq;
        for(char c:s)
        {
            freq[c]++;
        }
        for(char c:t)
        {
            if(freq[c] == 0 )
            {
                return false;
            }
            freq[c]--;
        }
        for(auto[ele,c]:freq)
        {
            if(c != 0)
            {
                return false;
            }
        }
        return true;
    }
};
