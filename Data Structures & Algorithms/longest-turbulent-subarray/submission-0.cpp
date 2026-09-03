class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, l =0, r = 1, prev = 0;

        while(r < arr.size())
        {
            if(arr[r] > arr[r-1] && prev != 1)
            {
                prev = 1;
                res = max(res, r - l + 1);
                r++;
            }
            else if(arr[r] < arr[r-1] && prev != 2)
            {
                prev = 2;
                res = max(res, r - l + 1);
                r++;
            }
            else
            {
                prev = 0;
                if(arr[r] == arr[r-1])
                {
                    l = r;
                    r = r + 1;
                }
                else
                {
                    l = r -1;
                }
            }
        }
        return res;
    }
};