class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto s:strs)
        {
            int len = s.length();
            string temp = to_string(len) + '#' + s;
            res += temp;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int i =0 ;
        int j =0 ;
        int n = s.length();
        while(i<n && j<n)
        {
            j = i;
            while(s[j] != '#')j++;
            int len = stoi(s.substr(i,j-i));
            string a = s.substr(j+1,len);
            res.push_back(a);
            i = j + len +1;
        }
        return res;
    }
};
