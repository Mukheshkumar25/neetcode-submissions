class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int l = 0;
        int r = 0;

        unordered_map<char, int> idx;

        int maxlen = 0;

        while (r < n) {

            char c = s[r];

            if (idx.find(c) != idx.end()) {

                l = max(l, idx[c] + 1);
            }

            idx[c] = r;

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};