class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r)
    {
        if(l < r)
        {
            int part = partition(nums, l, r);
            quickSort(nums, l, part-1);
            quickSort(nums, part+1, r);
        }
    }
    int partition(vector<int>& nums, int l, int r)
    {
        int key = nums[r];

        int ind = l;

        for(int i = l; i < r; i++)
        {
            if(nums[i] <= key)
            {
                swap(nums[i], nums[ind]);
                ind++;
            }
        }
        swap(nums[r], nums[ind]);
        return ind;
    }
};