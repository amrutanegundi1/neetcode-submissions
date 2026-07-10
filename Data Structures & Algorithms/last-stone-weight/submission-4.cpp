class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> st;

        for(auto itr : stones)
        {
            st.push(itr);
        }
        int counter = 0;
        while(st.size() > 1)
        {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if(t1 == t2)
            {
                st.push(0);
            }
            else {
                st.push(abs(t1-t2));
            }
        }
        return st.top();

    }
};
