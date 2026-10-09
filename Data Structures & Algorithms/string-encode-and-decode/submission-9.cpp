
class Solution {
public:

    string encode(vector<string>& strs) {
        string patt = "";

        for (string s : strs) {
            int len = s.length();
            patt += to_string(len) + '#' + s;
        }

        return patt;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.length()) {
            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Get actual string
            string word = s.substr(j + 1, len);

            res.push_back(word);

            // Move to next encoded string
            i = j + 1 + len;
        }

        return res;
    }
};

