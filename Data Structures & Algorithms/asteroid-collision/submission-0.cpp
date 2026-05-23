class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();               // top explodes, keep checking
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();               // both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;       // current asteroid explodes
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> res(st.size());
        for (int i = res.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
