class Solution {
public:
    string res;
    unordered_map<char,bool> visited;
    unordered_map<char, vector<char>> adj;
    string foreignDictionary(vector<string>& words) {
        unordered_set<char> s; 
        for(auto itr: words)
        {
            for(auto c : itr)
            {
                s.insert(c);
            }
        }

        

        for(auto itr : s)
        {
            adj[itr] = {};
        }

        for(int i = 0; i < words.size()-1; i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            int minLength = min(s1.length(), s2.length());
            if(s2.length() < s1.length() && s1.substr(0, minLength) == s2)
            {
                cout<<"Retuning here"<<endl;
                return "";
            }

            for(int i = 0; i < minLength; i++)
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
            if(dfs(itr.first))
            {
                cout<<"Loop detected: "<<itr.first<<endl;
                return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char c)
    {
        cout<<c<<endl;
        if(visited.find(c) != visited.end())
        {
            return visited[c];
        }
        visited[c] = true;
        for(auto itr : adj[c])
        {
            if(dfs(itr))
            {
                return true;
            }
        }

        visited[c] = false;
        res += c;
        return false;
    }
};
