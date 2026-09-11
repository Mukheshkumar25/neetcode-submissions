
class Solution {
public:
    bool isValid(string st) {
        stack<char> s;

        for (char c : st)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                s.push(c);
            }
            else if (!s.empty() && s.top() == '(' && c == ')')
            {
                s.pop();
            }
            else if (!s.empty() && s.top() == '[' && c == ']')
            {
                s.pop();
            }
            else if (!s.empty() && s.top() == '{' && c == '}')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }

        return s.empty();
    }
};

