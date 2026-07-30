class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(), INT_MAX);
        res[nums.size()-1] = 0;

        for(int i = nums.size()-1; i >= 0; i--)
        {
            int count = nums[i];
            for(int j = 0; j < count; j++)
            {
                if(i+j+1 < nums.size() && res[i+j+1] != INT_MAX)
                {
                    res[i] = min(res[i], 1 + res[i+j+1]);
                }
            }
        }
        return res[0];
        
    }
};
