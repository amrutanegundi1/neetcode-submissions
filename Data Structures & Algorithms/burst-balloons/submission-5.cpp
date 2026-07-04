class Solution {
public:
    map<pair<int,int>, int> dp;
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return dfs(1, nums.size()-2, nums);
    }

    int dfs(int l, int r, vector<int>& nums)
    {
        if(l > r)
        {
            return 0;
        }
        pair<int,int> pr = pair<int,int>(l, r);
        if(dp.find(pr) != dp.end())
        {
            return dp[pr];
        }
        for(int i = l; i <= r; i++)
        {
            int coins = nums[i] * nums[l-1] * nums[r+1];
            coins += dfs(l, i-1, nums) + dfs(i + 1, r, nums);
            if(dp.find(pr) != dp.end())
            {
                dp[pr] = max(dp[pr], coins);
            }
            else
            {
                dp[pr] = coins;
            }
        }
        return dp[pr];
    }
};
