class Solution {
public:
    map<pair<int,int>, int> mp;
    int lengthOfLIS(vector<int>& nums) {
        // vector<int> res(nums.size(), 1);
        // for(int i = nums.size()-2; i >= 0; i--)
        // {
        //     for(int j = i+1; j < nums.size(); j++)
        //     {
        //         if(nums[i] < nums[j])
        //             res[i] =  max(res[i], 1 + res[j]);
        //     }
        // }
        // int result = res[0];
        // for(int i = 1; i < res.size(); i++)
        // {
        //     result = max(result, res[i]);
        // }
        // return result;

        return dfs(nums, 0, INT_MIN);
    }
    int dfs(vector<int>& nums, int i, int prev)
    {
        if(mp.find(pair<int,int>(i, prev)) != mp.end())
        {
            return mp[pair<int,int>(i, prev)];
        }
        if(i >= nums.size())
        {
            return 0;
        }
        int res1 = dfs(nums, i+1, prev);
        if(nums[i] > prev)
        {
            int res2 = 1 + dfs(nums, i+1, nums[i]);
            mp[pair<int,int>(i, prev)] = max(res1, res2);    
            return mp[pair<int,int>(i, prev)];
        }
        mp[pair<int,int>(i, prev)] = res1;
        return res1;
    }
};
