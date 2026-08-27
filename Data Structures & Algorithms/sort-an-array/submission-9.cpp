class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r, vector<int>& temp)
    {
        if(l < r)
        {
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid, temp);
            mergeSort(nums, mid+1, r, temp);
            merge(nums,l,mid,r, temp);
        }
    }

    void merge(vector<int>& nums, int l, int mid, int r, vector<int>& temp)
    {
        //int s1 = mid-l+1, s2 = r - mid;
        //vector<int> a1(s1), a2(s2);
        for(int i = l, j = 0; i <= mid; i++, j++)
        {
            temp[i] = nums[i];
        }

        for(int i = mid+1, j = 0; i <= r; i++, j++)
        {
            temp[i] = nums[i];
        }
        int i1 = l, i2 = mid+1, i3 = l;
        while(i1 <= mid && i2 <= r)
        {
            if(temp[i1] <= temp[i2])
            {
                nums[i3++] = temp[i1++];
            }
            else
            {
                nums[i3++] = temp[i2++];
            }
        }
        while(i1 <= mid)
        {
            nums[i3++] = temp[i1++];
        }

    }

};