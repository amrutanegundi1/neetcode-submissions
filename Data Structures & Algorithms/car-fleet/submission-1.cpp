class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pr;
        for(int i = 0; i < position.size(); i++)
        {
            pr.push_back(pair<int,int>(position[i], speed[i]));
        }
        sort(pr.rbegin(),pr.rend());

        stack<double> st;

        for(int i = 0; i < pr.size(); i++)
        {
            if(st.empty())
            {
                st.push((double)(target - pr[i].first)/pr[i].second);
            }
            else
            {
                double tm = (double)(target - pr[i].first)/pr[i].second;
                if(st.top() >= tm)
                {
                    continue;
                }
                else
                {
                    st.push((double)(target - pr[i].first)/pr[i].second);
                }
            }
        }
        return st.size();
    }
};
