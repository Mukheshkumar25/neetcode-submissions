class Solution {
public:
    int climbStairs(int n) {
        int p1 = 1;
        int p2 = 1;
        for(int i = 2;i<=n;i++)
        {
            int res = p1 + p2;
            p1 = p2;
            p2 = res;
        }
        cout<<p1<<p2;
        return p2;
    }
};
