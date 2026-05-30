class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1));
        
    }

    int helper(vector<int>& nums, int s, int e)
    {
        int rob1 = 0, rob2 = 0;
        for(int i = s; i <= e; i++)
        {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};
