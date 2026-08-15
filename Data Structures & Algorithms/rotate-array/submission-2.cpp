class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k == 0)
        {
            return;
        }
        int numOfReplacements = 0;
        int start = 0, temp1, temp2;
        while(numOfReplacements < nums.size())
        {
            int curr = start;
            temp1 = nums[curr];
            do
            {
                temp2 = nums[(curr + k) % nums.size()];
                nums[(curr + k) % nums.size()] = temp1;
                
                temp1 = temp2;
                numOfReplacements++;
                curr = (curr + k) % nums.size();
            }while(curr != start);
            start++;
        }
        
    }
};