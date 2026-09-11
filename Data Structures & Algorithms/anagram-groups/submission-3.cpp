class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string ,vector<string>>pat;
        for(auto s:strs)
        {
            vector<int>ha(26,0);
            for(auto c:s)
            {
                ha[c-'a']++;
            }
            string patt = ""; 
            for (int i : ha)
             { 
                patt += to_string(i) + "#";
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
