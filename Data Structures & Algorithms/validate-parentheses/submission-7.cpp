
class Solution {
public:
    bool isValid(string s) {
        string st = "";

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st += c;
            }
            else if (st.empty()) {
                return false;
            }
            else if (c == ')' && st.back() == '(') {
                st.pop_back();
            }
            else if (c == ']' && st.back() == '[') {
                st.pop_back();
            }
            else if (c == '}' && st.back() == '{') {
                st.pop_back();
            }
            else {
                return false;
            }
        }

        return st.empty();
    }
};
