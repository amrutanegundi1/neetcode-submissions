class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        nums.resize(size*2);

        for(int i = 0; i < size; i++)
        {
            nums[size + i] = nums[i];
        }
        return nums;
    }
};