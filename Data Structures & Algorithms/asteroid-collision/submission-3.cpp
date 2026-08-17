class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // collision happens only if top of the stack is moving to the right(+ve) and incoming is moving to the left(-ve)
        stack<int> st;
        st.push(asteroids[0]);
        for(int i = 1; i < asteroids.size(); i++)
        {
            int num = asteroids[i];
            bool needToPush = true;
            while(!st.empty() && st.top() > 0 && num < 0)
            {
                if(abs(st.top()) == abs(num))
                {
                    needToPush = false;
                    st.pop();
                    break;
                }
                else if(st.top() > abs(num))
                {
                    needToPush = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(needToPush)
            {
                st.push(num);
            }
        }
        vector<int> res(st.size());
        int i = st.size()-1;
        while(!st.empty())
        {
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
};