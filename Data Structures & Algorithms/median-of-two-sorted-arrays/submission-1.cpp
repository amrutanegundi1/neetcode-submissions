class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> que;

        for(auto itr : nums1)
            que.push(itr);
        for(auto itr : nums2)
            que.push(itr);
        
        int total = nums1.size() + nums2.size();
        int mid = (nums1.size() + nums2.size())/2;

        while(que.size() > mid + 1)
        {
            que.pop();
        }
        double res = 0.0;
        if(total % 2 == 0)
        {
            res = que.top();
            que.pop();
            res += que.top();
            res /= 2; 
        }
        else
        {
            res = que.top();
        }
        return res;
    }
};
