class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(nums[i] <= 0)
            {
                nums[i] = size + 1;
            }
        }
        for(int i = 0; i < size; i++)
        {
            if(abs(nums[i]) <= nums.size() && nums[abs(nums[i])-1] > 0)
            {
                nums[abs(nums[i])-1] = nums[abs(nums[i])-1] * -1;
            }
        }
        
        for(int i = 1; i <= nums.size(); i++)
        {
            if(nums[i-1] > 0)
            {
                return i;
            }
        }
        return size+1;
    }
};