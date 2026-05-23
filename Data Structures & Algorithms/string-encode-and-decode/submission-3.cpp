class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto &s :strs)
        {
            res += (to_string(s.length()) + '#' + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        int n = s.length();
        vector<string>res;
        while(i<n)
        {
            int j = i;
            while(s[j] !='#')j++;
            int len = stoi(s.substr(i,j-i));
            string to_add = s.substr(j+1,len);
            res.push_back(to_add);
            i = j + len + 1;
        }
        return res;
    }
};
