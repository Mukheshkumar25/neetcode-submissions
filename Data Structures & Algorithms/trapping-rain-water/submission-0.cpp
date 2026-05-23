class Solution {
public:
    int trap(vector<int>& heights) {
      int n = heights.size();
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++)
        {
            left[i] = max(heights[i-1],left[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(heights[i+1],right[i+1]);
        }
        int total =0 ;
        for(int i=0;i<n;i++)
        {
            total += max(0,(min(left[i],right[i]) - heights[i]));
        }
        return total;  
    }
};
