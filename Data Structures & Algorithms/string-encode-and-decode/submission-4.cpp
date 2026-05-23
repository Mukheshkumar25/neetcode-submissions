class Solution {
public:

    string encode(vector<string>& strs) {
        string res= "";
        for(auto s:strs)
        {
            res += (to_string(s.length()) + '#' + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        int  i =0;
        int j=0;
        vector<string>res;
        int n =s.length();
        while(i<n)
        {
            int j=i;
            while(s[j]!='#')j++;
            int num = stoi(s.substr(i,j-i));
            string to_add = s.substr(j+1,num);
            res.push_back(to_add);
            i = j + num +1;
        }


        return res;
    }
};
