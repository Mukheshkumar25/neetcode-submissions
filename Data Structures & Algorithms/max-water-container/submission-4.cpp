class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0;
        int n = heights.size();
        int h = n-1;
        int maxi = 0;
        while(l < h)
        {
            int dist = h - l;
            maxi = max(maxi , min(heights[l],heights[h]) * dist);
            heights[h] < heights[l] ? h--:l++;
        }
        return maxi;
    }
};
