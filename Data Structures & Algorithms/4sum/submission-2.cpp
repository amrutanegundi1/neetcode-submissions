class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        if(nums.size() < 4)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++)
        {
            for(int j = i+1; j < nums.size()-2; j++)
            {
                int l = j+1, r = nums.size()-1;

                while(l < r)
                {
                    long long num = long(nums[i]) + nums[j] + nums[l] + nums[r]; 
                    if(num == target)
                    {
                        res.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if(num > target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
        
    }
};