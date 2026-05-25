class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i]>0)
            {
                break;
            }
            int l = i+1, r = nums.size()-1;
            while(l < r)
            {
                int threeSum = nums[i] + nums[l] + nums[r];
                if(threeSum == 0)
                {
                    res.insert({nums[i], nums[l], nums[r]});
                    l++, r--;
                } 
                else if(threeSum > 0)
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
