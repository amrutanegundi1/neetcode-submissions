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
            int p = partition(nums,l,r);
            quickSort(nums, l, p-1);
            quickSort(nums, p+1, r);
        }
    }

    int partition(vector<int>& nums, int l, int r)
    {
        int res = l;
        int key = nums[r];

        for(int j = l; j <= r; j++)
        {
            if(nums[j] < key)
            {
                swap(nums[j], nums[res]);
                res++;
            }
        }
        swap(nums[res], nums[r]);
        return res;


    }
};