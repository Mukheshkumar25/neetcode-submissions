class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>groups;
        for(string s:strs)
        {
            vector<int>arr(26,0);
            for(auto c:s)
            {
                arr[c-'a']++;
            }
            string key;
            for(int i : arr)
            {
                key += to_string(i) + '#';
            }
            groups[key].push_back(s);
        }
        vector<vector<string>>res;
        for(auto &pair:groups)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
