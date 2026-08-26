class Solution {
   public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int length = sum / 4;
        for (int i = 0; i < matchsticks.size(); i++) {
            if (matchsticks[i] > length) {
                return false;
            }
        }
        sort(matchsticks.begin(), matchsticks.end());
        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, 0, length);
    }

   private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int i, int len) {
        if (i == matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }

        for (int j = 0; j < 4; j++) {
            if (sides[j] + matchsticks[i] <= len) {
                sides[j] += matchsticks[i];
                if (dfs(matchsticks, sides, i + 1, len)) return true;
                sides[j] -= matchsticks[i];
            }
        }

        return false;
    }
};