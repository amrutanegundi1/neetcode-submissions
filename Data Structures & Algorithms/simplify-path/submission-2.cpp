class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string curr;
        while(getline(ss, curr, '/'))
        {
            if(curr == "..")
            {
                if(!st.empty())
                    st.pop_back();
            }
            else if(curr != "." && curr.length() > 0)
            {
                st.push_back(curr);
            }
        }
        string result = "/";
        int size = st.size();
        for(int i = 0; i < size; i++)
        {
            if(i != size-1)
                result += st[i] + '/';
            else
                result += st[i];
        }
        return result;
    }
};