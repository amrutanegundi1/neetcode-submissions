class DSU
{
    vector<int> parent, rank;
public:
    DSU(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        int curr = node;
        if(parent[curr] != curr)
        {
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    void unionSet(int n1, int n2)
    {
        int p1 = find(n1);
        int p2 = find(n2);
        if(p1 == p2)
        {
            return;
        }
        if(rank[p1] >= rank[p2])
        {
            rank[p1] += rank[p2];
            parent[p2] = p1;
        }
        else
        {
            rank[p2] += rank[p1];
            parent[p1] = p2;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> mp;
        int n = accounts.size();
        DSU dsu(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    dsu.unionSet(i, mp[accounts[i][j]]);
                }
            }
        }
        unordered_map<int, vector<string>> accToEmail(n);
        for(auto itr : mp)
        {
            int parent = dsu.find(itr.second);
            accToEmail[parent].push_back(itr.first);
        }
        vector<vector<string>> res;
        for(auto itr : accToEmail)
        {
            vector<string> inst;
            inst.push_back(accounts[itr.first][0]);
            vector<string> emails = itr.second;
            sort(emails.begin(), emails.end());
            inst.insert(inst.end(), emails.begin(), emails.end());
            res.push_back(inst);
        }
        return res;

        
    }
};