class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int maxLeft = height[0], maxRight = height[height.size()-1]; 
        while(l < r)
        {
            if(maxLeft < maxRight)
            {
                if(maxLeft - height[l] > 0)
                {
                    res += maxLeft - height[l];
                }
                l++;
                maxLeft = max(maxLeft, height[l]);
            }
            else
            {
                if(maxRight - height[r] > 0)
                {
                    res += maxRight - height[r];
                }
                r--;
                maxRight = max(maxRight, height[r]);

            }
        }
        return res;
    }
};
