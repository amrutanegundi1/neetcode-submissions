class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l < r)
        {
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums,l,mid,r);
        }
    }

    void merge(vector<int>& nums, int l, int mid, int r)
    {
        int s1 = mid-l+1, s2 = r - mid;
        vector<int> a1(s1), a2(s2);
        for(int i = l, j = 0; i <= mid; i++, j++)
        {
            a1[j] = nums[i];
        }

        for(int i = mid+1, j = 0; i <= r; i++, j++)
        {
            a2[j] = nums[i];
        }
        int i1 = 0, i2 = 0, i3 = l;
        while(i1 < s1 && i2 < s2)
        {
            if(a1[i1] <= a2[i2])
            {
                nums[i3++] = a1[i1++];
            }
            else
            {
                nums[i3++] = a2[i2++];
            }
        }
        while(i1 < s1)
        {
            nums[i3++] = a1[i1++];
        }

    }

};