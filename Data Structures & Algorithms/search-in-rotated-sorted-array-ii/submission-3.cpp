class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            cout<<mid<<endl;
            if (nums[mid] == target) {
                return true;
            } else if (nums[r] > nums[mid]) { // right sorted
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else if (nums[r] < nums[mid]) { //left sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            else
            {
                r--;
            }
        }
        return false;
    }
};