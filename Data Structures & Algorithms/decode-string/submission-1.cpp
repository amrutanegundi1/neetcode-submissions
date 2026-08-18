class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        string curr = "";
        for(auto itr : s)
        {
            if(itr == '[')
            {
                st.push_back(curr);
                curr = "";
                st.push_back("[");
            }
            else if(itr == ']')
            {
                string str;
                if(curr.length() > 0)
                {
                    str = curr;
                    string pop = st.back();
                    st.pop_back();
                    while(pop != "[")
                    {
                        str = pop + str;
                        pop = st.back();
                        st.pop_back();
                    }
                }
                else
                {
                    str = st.back();
                    st.pop_back();
                    string pop = st.back();
                    st.pop_back();
                    while(pop != "[")
                    {
                        str = pop + str;
                        pop = st.back();
                        st.pop_back();
                    }
                }
                curr = "";
                string num =  st.back();
                st.pop_back();
                for(int i = 0; i < stoi(num); i++)
                {
                    curr += str;
                }
                st.push_back(curr);
                curr = "";
            }
            else if(itr >= '1' && itr <= '9')
            {
                if(curr.length() == 0 || (curr[curr.length()-1] >= '1' && curr[curr.length()-1] <= '9'))
                {
                    curr += itr;
                }
                else
                {
                    st.push_back(curr);
                    curr = itr;
                }
            }
            else
            {
                curr += itr;
            }
        }
        if(curr.length() > 0)
        {
            st.push_back(curr);
        }
        string result = "";
        for(int i = 0; i < st.size(); i++)
        {
            result += st[i];
        }
        return result;
    }
};