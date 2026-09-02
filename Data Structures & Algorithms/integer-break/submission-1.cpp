class Solution {
    unordered_map<int, int> mp;

   public:
    int integerBreak(int n) {
        mp[1] = 1;
        return dfs(n, n);
    }
    int dfs(int num, int n) {
        if (mp.find(num) != mp.end()) {
            return mp[num];
        }
        int res = (num == n) ? 0 : num;
        for (int k = 1; k < num; k++) {
            int temp = dfs(num - k, n) * dfs(k, n);
            cout << temp << endl;
            res = max(res, temp);
        }
        cout << n << " " << res << endl;
        mp[num] = res;
        return res;
    }
};