class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = nums.size()/2;
        int res = nums[0], temp = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                temp++;
                if(temp > count)
                {
                    res = nums[i];
                    break;
                }

            }
            else
            {
                temp = 1;
            }
        }
        return res;
        
    }
};