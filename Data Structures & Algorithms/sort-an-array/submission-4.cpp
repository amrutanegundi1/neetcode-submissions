class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r)
    {
        int mid = l + (r-l)/2;
        if(l < r)
        {
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums,l, mid, r);
        }
    }

    void merge(vector<int>& nums, int l, int m, int r)
    {
        vector<int> cp1(m-l+1);
        vector<int> cp2(r-m);
        int  i = l, j =0;
        while(i <= m)
        {
            cp1[j++] = nums[i++];
        }
        i = m+1, j =0;
        while(i <= r)
        {
            cp2[j++] = nums[i++];
        }
        int n1 = cp1.size();
        int n2 = cp2.size();
        int start = l;
        i = 0, j = 0;
        while(i < n1  && j < n2)
        {
            if(cp1[i] < cp2[j])
            {
                nums[start++] = cp1[i++];

            }
            else
            {
                nums[start++] = cp2[j++];
            }
        }
        while(i < n1)
        {
            nums[start++] = cp1[i++];
        }
        while(j < n2)
        {
            nums[start++] = cp2[j++];
        }
    }
};