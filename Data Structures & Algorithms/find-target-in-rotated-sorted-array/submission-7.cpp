class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int pivot = findPivot(nums);
        // int ind = binarySearch(nums, pivot, nums.size()-1,target);
        // if(ind == -1 && pivot > 0)
        // {
        //     ind = binarySearch(nums, 0, pivot-1,target);
        // }
        // return ind;
        return binarySearch(nums, 0, nums.size()-1,target);
    }
    int binarySearch(vector<int>& nums, int l, int r, int target)
    {

        while(l<=r)
        {
            int m = l+ (r-l)/2;
            if(nums[m] == target)
            {
                return m;
            }
            else if(nums[l] <= nums[m])
            {
                if(target >= nums[l] && target < nums[m])
                {
                    r = m -1;
                }
                else
                {
                    l = m + 1;
                }
                
            }
            else
            {
                if(target > nums[m] && target <= nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
    int findPivot(vector<int>& nums)
    {
        int ind = 0, l = 0, r = nums.size()-1, minVal =nums[0]; 

        while(l <= r)
        {
            if(nums[l] < nums[r])
            {
                if(nums[l] < minVal)
                {
                    ind = l;
                    break;
                }
            }

            int m = l + (r-l)/2;

            if(nums[m] < minVal)
            {
                minVal = nums[m];
                ind = m;
            }
            if(nums[m] >= nums[l])
            {
                l = m + 1;
            }
            else
            {
                r = m -1;
            }
        }
        return ind;
    }
};
