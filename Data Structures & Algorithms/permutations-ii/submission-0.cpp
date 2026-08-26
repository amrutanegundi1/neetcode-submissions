class Solution {
public:
    set<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums, 0, nums.size()-1);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void permute(vector<int>& nums, int l, int h)
    {
        if(l == h)
        {
            res.insert(nums);
        }
        for(int i = l; i <= h; i++)
        {
            swap(nums[i], nums[l]);
            permute(nums, l+1, h);
            swap(nums[i], nums[l]);
        }
    }
};