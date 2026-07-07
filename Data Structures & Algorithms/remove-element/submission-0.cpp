class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size()-1;
        int k = 0;
        int i = 0;
        while(i <= j)
        {
            if(nums[i] != val)
            {
                k++;
                i++;
            }
            else
            {
                swap(nums[i], nums[j]);
                j--;
            }
        }
        return k;
    }
};