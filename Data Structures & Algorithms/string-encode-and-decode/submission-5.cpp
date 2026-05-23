class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s:strs)
        {
            res = res + (to_string(s.length()) + '#'+ s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int i =0;
        int j = 0;
        int n = s.length();
        while(i<n && j<n )
        {
            j=i;
            while(s[j] != '#')j++;
            int num = stoi(s.substr(i,j-i));
            string a = s.substr(j+1,num);
            res.push_back(a);
            i = j + num + 1;
        }
        return res;
    }
};
