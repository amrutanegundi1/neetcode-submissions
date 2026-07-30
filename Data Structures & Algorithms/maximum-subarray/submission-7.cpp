class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int currsum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(currsum < 0)
            {
                currsum = nums[i];
            }
            else
            {
                currsum+= nums[i];
            }
            res = max(res, currsum);
        }
        return res;

    }
};
