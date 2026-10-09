class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>pat;
        for(auto s:strs)
        {
            vector<int>f(26,0);
            for(auto c:s)
            {
                f[c-'a']++;
            }
            string patt = "";
            for(auto i:f)
            {
                patt += to_string(i) + '#';
            }
            pat[patt].push_back(s);
        }
        for(auto[p,v]:pat)
        {
            res.push_back(v);
        }
        return res;
    }
};
