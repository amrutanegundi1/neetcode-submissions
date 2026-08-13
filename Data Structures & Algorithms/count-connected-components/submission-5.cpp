class DSU
{
    public:
    vector<int> rank, parent;
    DSU(int n)
    {
        rank.resize(n, 1);
        for(int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }
    int findParent(int i)
    {
        int curr = i;
        while(parent[curr] != curr)
        {
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    int unionSet(int n1, int n2)
    {
        int p1 = findParent(n1);
        int p2 = findParent(n2);

        if(p1 == p2)
        {
            return 0;
        }
        else
        {
            int r1 = rank[p1];
            int r2 = rank[p2];

            if(r1 >= r2)
            {
                parent[p2] = parent[p1];
                rank[p1] += rank[p2];
            }
            else
            {
                parent[p1] = parent[p2];
                rank[p2] += rank[p1];
            }
        }
        return 1;
    }
};
class Solution {

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu = DSU(n);
        for(auto itr : edges)
        {
            if(dsu.unionSet(itr[0], itr[1]))
            {
                n--;
            }
        }
        return n;
    }
};
