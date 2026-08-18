class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string curr;
        while(getline(ss, curr, '/'))
        {
            cout<<curr<<endl;
            if(curr == "..")
            {
                if(!st.empty())
                    st.pop_back();
            }
            else if(curr != "." && curr.length() > 0)
            {
                cout<<"pushing: "<<curr<<endl;
                st.push_back(curr);
            }
        }
        string result = "/";
        for(int i = 0; i < st.size(); i++)
        {
            if(i != st.size()-1)
                result += st[i] + '/';
            else
                result += st[i];
        }
        return result;
    }
};