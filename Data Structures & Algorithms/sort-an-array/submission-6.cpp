class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();
        for(int i = n/2; i >= 0; i--)
        {
            heapify(nums, n, i);
        }

        for(int i = n-1; i >= 0; i--)
        {
            swap(nums[i], nums[0]);
            heapify(nums,i,0);
        }
        return nums;      
    }

    void heapify(vector<int>& nums, int n, int large)
    {
        int ip = large;
        int l = 2*large + 1;
        int r = 2*large + 2;
        if(l < n && nums[large] < nums[l])
        {
            large = l;
        }
        if(r < n && nums[large] < nums[r])
        {
            large = r;
        }
        if(ip != large)
        {
            swap(nums[large], nums[ip]);
            heapify(nums,n,large);
        }
    }
};