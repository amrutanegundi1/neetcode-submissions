class DSU
{
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n)
        {
            rank.resize(n, 1);
            parent.resize(n);
            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int findSet(int node)
        {
            int curr = node;

            while(parent[curr] != curr)
            {
                parent[curr] = parent[parent[curr]];
                curr = parent[curr];
            }
            return curr;
        }

        int unionSet(int n1, int n2)
        {
            int p1 = findSet(n1);
            int p2 = findSet(n2);

            if(p1 == p2)
            {
                return 0;
            }

            if(rank[p1] > rank[p2])
            {
                parent[p2] = p1;
                rank[p1] += rank[p2]; 
            }
            else
            {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
            return 1;
        }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        int res = n;
        DSU dsu(n);

        for(auto itr : edges)
        {
            if(dsu.unionSet(itr[0], itr[1]) == 1)
            {
                res--;
            }
        }
        return res;
    }
};
