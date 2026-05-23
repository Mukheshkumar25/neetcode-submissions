class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxl =0 ;
        int maxr =0 ;
        int total =0 ;
        int l =0 ;
        int r = n-1;
        while(l<r)
        {
            maxl = max(maxl,height[l]);
            maxr = max(maxr,height[r]);
            if(maxl < maxr)
            {
              total += (maxl - height[l]);
              l++;  
            }
            else
            {
                total += (maxr - height[r]);
                r--;
            }
        }
        return total;
    }
};
