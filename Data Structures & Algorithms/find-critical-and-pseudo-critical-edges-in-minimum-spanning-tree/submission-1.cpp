class DSU {
   public:
    vector<int> rank, parent;
    DSU(int n) {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        int curr = node;
        while (parent[curr] != curr) {
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    bool unionSet(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
class SOR {
   public:
    bool operator()(vector<int> a1, vector<int> a2) { return (a1[2] < a2[2]); }
};
class Solution {
   public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), SOR());
        int minWeight = 0;
        for (auto itr : edges) {
            if (dsu.unionSet(itr[0], itr[1])) {
                minWeight += itr[2];
            }
        }
        vector<int> critical, pseudo;

        for (int i = 0; i < edges.size(); i++) {
            DSU d2(n);
            int weight = 0;
            for (auto itr1 : edges) {
                if (itr1[3] == edges[i][3]) continue;
                if (d2.unionSet(itr1[0], itr1[1])) {
                    weight += itr1[2];
                }
            }

            int maxRank = 0;
            for (auto itr : d2.rank) {
                if (itr > maxRank) {
                    maxRank = itr;
                }
            }

            if (weight > minWeight || maxRank != n) {
                critical.push_back(edges[i][3]);
            } else {
                DSU d3(n);
                int weight2 = edges[i][2];
                d3.unionSet(edges[i][0], edges[i][1]);
                for (auto itr2 : edges) {
                    if (d3.unionSet(itr2[0], itr2[1])) {
                        weight2 += itr2[2];
                    }
                }
                if (weight2 == minWeight) {
                    pseudo.push_back(edges[i][3]);
                }
            }
        }

        return {critical, pseudo};
    }
};