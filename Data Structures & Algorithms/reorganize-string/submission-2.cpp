class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto itr : s)
        {
            mp[itr]++;
        }
        priority_queue<pair<int, char>> que;
        for(auto itr : mp)
        {
            que.push({itr.second, itr.first});
        }
        string result = "";
        bool toPush = false;
        pair<int, char> pp;
        while(!que.empty())
        {
            pair<int, char> pr = que.top();
            que.pop();
            result += pr.second;
            if(toPush == false && pr.first > 1 && que.empty())
            {
                return "";
            }
            if(toPush)
            {
                toPush = false;
                que.push(pp);
            }
            if(pr.first > 1)
            {
                toPush = true;
                pp = {pr.first-1, pr.second};
            }
        }
        return result;
        
    }
};