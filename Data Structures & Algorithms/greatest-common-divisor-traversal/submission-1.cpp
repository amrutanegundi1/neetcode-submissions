class DSU {
   public:
    vector<int> rank, parent;
    int siz;

    DSU(int n) {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        siz = n;
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
            rank[p1] += rank[p2];
            parent[p2] = p1;
        } else {
            rank[p2] += rank[p1];
            parent[p1] = p2;
        }
        siz--;
        return true;
    }
};
class Solution {
   public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, int> fact_ind;
        DSU dsu(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int f = 2;
            while (f * f <= nums[i]) {
                if (nums[i] % f == 0) {
                    if (fact_ind.find(f) != fact_ind.end()) {
                        dsu.unionSet(i, fact_ind[f]);
                    } else {
                        fact_ind[f] = i;
                    }

                    while (nums[i] % f == 0) {
                        nums[i] = nums[i] / f;
                    }
                }
                f++;
            }
            if (nums[i] > 1) {
                if (fact_ind.find(nums[i]) != fact_ind.end()) {
                    dsu.unionSet(i, fact_ind[nums[i]]);
                } else {
                    fact_ind[nums[i]] = i;
                }
            }
        }
        cout<<dsu.siz<<endl;
        return dsu.siz == 1;
    }
};