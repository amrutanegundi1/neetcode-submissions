class Solution {
    class DSU
    {
        private:
            vector<int> rank;
            vector<int> par;
        public:
            DSU(int n)
            {
                rank.resize(n,1);
                par.resize(n);
                for(int i = 0; i < n; i++)
                {
                    par[i] = i;
                }
            }
            int findParent(int n)
            {
                int curr = n;
                while(par[curr] != curr)
                {
                    par[curr] = par[par[curr]];
                    curr = par[curr];
                }
                return curr;
            }

            bool unionNode(int n1, int n2)
            {
                int p1 = findParent(n1);
                int p2 = findParent(n2);

                if(p1 == p2)
                {
                    return false;
                }

                if(rank[p1] >= rank[p2])
                {
                    par[p2] = par[p1];
                    rank[p1] += rank[p2];
                }
                else
                {

                    par[p1] = par[p2];
                    rank[p2] += rank[p1];
                }
                return true;
            }
    };
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto itr : edges)
        {
            if(dsu.unionNode(itr[0], itr[1]))
            {
                n--;
            }
        }
        return n;
    }
};
