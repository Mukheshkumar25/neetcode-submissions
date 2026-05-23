class Solution {
public:
    int maxArea(vector<int>& heights) {
       int n = heights.size();
       int l = 0 ;
       int r  = n-1;
       int maxw = 0;
       while(l<n && r>=0 &&l<r)
       {
        int h = min(heights[l],heights[r]);
        int wat = h * (r - l);
        maxw = max(maxw,wat);

        heights[l] < heights[r] ? (l++) : (r--);
       }
       return maxw;
    }
};
