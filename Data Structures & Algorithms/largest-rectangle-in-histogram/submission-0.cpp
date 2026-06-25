class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;
        stack<pair<int,int>> st;

        for(int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while(!st.empty())
            {
                pair<int,int> pr = st.top();

                if(pr.first <= heights[i])
                {
                    break;
                }
                else
                {
                    st.pop();
                    maxArea = max(maxArea, (pr.first * (i - pr.second)));
                    start = pr.second;
                }
            }
            st.push(pair<int,int>(heights[i], start));

        }
        while(!st.empty())
        {
            pair<int,int> pr = st.top();
            st.pop();
            int area = (pr.first * (heights.size() - pr.second));
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
