class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int l = 0, r = nums.size()-1;
        int i = 0;
        int distinct = nums.size();
        while(l < r)
        {
            if(nums[l] == nums[l+1])
            {
                l++;
                distinct--;
            }
            else
            {
                nums[i++] = nums[l++];
            }
        }
        nums[i++] = nums[l++];
        return distinct;
    }
};