class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size*2);

        for(int i = 0; i < size; i++)
        {
            res[i] = nums[i];
            res[size + i] = nums[i];
        }
        return res;
    }
};