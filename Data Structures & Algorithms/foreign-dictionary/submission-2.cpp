class Solution {
public:
    unordered_map<char, bool> visit;
    unordered_map<char, vector<char>> adj;
    string result = "";
    string foreignDictionary(vector<string>& words) {
        
        unordered_set<char> st;
        for(auto itr : words)
        {
            for(auto c : itr)
            {
                st.insert(c);
            }
        }
        for(auto itr : st)
        {
            adj[itr] = {};
        }
        for(int i = 0; i < words.size()-1; i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            int minLen = min(s1.length(), s2.length());
            if(s1.length() > s2.length() && s1.substr(0, minLen) == s2)
            {
                return "";
            }
            for(int i = 0; i < minLen; i++)
            {
                if(s1[i] != s2[i])
                {
                    adj[s1[i]].push_back(s2[i]);
                    break;
                }
            }
        }
        for(auto itr : adj)
        {
            cout<<itr.first<<endl;
            if(dfs(itr.first))
            {
                return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(char c)
    {
        if(visit.find(c) != visit.end())
        {
            return visit[c];
        }

        visit[c] = true;
        for(auto itr : adj[c])
        {
            if(dfs(itr))
            {
                return true;
            }
        }
        visit[c] = false;
        cout<<c<<endl;
        result += c;
        return false;
    }
};
