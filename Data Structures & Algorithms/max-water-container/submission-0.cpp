class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        for(int i = 0; i< heights.size()-1; i++)
        {
            for(int j= i+1; j < heights.size(); j++)
            {
                maxarea = max(maxarea, min(heights[i],heights[j])*(j-i));
            }
        }
        return maxarea;
    }
};
