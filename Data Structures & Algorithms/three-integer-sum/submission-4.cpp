class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int l = i+1, r = nums.size()-1;
            int sum = nums[i];
            while(l < r)
            {
                if(nums[i] + nums[l] + nums[r] == 0)
                {
                    res.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if(nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
        
    }
};
