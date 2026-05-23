class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>f1,f2;
        for(auto c:s)
        {
            f1[c-'a']++;
        }
        for(auto c:t)
        {
            f2[c-'a']++;
        }
        return f1 == f2;
    }
};
