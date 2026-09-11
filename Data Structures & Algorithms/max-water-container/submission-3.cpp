class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l =0 ;
        int r = n-1;
        int maxi = 0;
        while(l<r)
        {
            int h  = min(heights[l],heights[r]);
            int d = r - l;
            maxi = max(maxi,h*d);
            heights[l] < heights[r] ? l++ : r--;
        }
        return maxi;
    }
};
