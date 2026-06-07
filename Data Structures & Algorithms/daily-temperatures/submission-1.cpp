class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);

        stack<pair<int,int>> st;

        for(int i =0; i < temperatures.size(); i++)
        {
            while(!st.empty() && st.top().first < temperatures[i])
            {
                pair<int, int> pr = st.top();
                st.pop();
                results[pr.second] = i - pr.second;
            }
            st.push(pair<int,int>(temperatures[i], i));
        }
        return results;
    }
};
