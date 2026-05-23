class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string res = "";
        for(int i =0 ;i<strs[0].length();i++)
        {
            char c = strs[0][i];
            bool found = true;
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i] !=c)
                {
                    found = false;
                    break;
                }
            }
            if(found == false)
            {
                break;
            }
            else
            {
                res += c;
            }
        }   
        return res;
    }
};