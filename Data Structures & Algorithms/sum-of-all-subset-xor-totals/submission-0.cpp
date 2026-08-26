class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subset;
        subset.push_back({});
        for (int j = 0; j < nums.size(); j++) {
            int size = subset.size();
            for (int i = 0; i < size; i++) {
                vector<int> temp = subset[i];
                temp.push_back(nums[j]);
                subset.push_back(temp);
            }
        }
        int res = 0;
        for(int i = 0; i < subset.size(); i++)
        {
            int temp = 0;
            for(int j = 0; j < subset[i].size(); j++)
            {
                temp ^= subset[i][j];
            }
            res += temp;
        }
        return res;
    }
};