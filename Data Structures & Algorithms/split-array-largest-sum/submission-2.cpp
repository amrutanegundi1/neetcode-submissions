class Solution {
public:
    map<pair<int,int>, int> mp;
    int splitArray(vector<int>& nums, int k) {
        return dfs(nums, k, 0);
        
        // for(auto itr : splits)
        // {
        //     for(auto i : itr)
        //     {
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    int dfs(vector<int>& nums, int k, int i)
    {
        if(i == nums.size() && k >= 0)
        {
            return 0;
        }
        if(k <= 0)
        {
            return INT_MAX;
        }
        pair<int,int> pr(i,k);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }
        int sum = 0, minSum = INT_MAX;
        for(int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            minSum = min(minSum, max(sum, dfs(nums, k-1, j + 1)));
        }
        mp[pr] = minSum;
        return minSum;
    }
};