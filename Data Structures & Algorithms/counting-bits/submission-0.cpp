class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i= 0; i <= n; i++)
        {
            result[i] = numofBits(i);\
        }
        return result;
    }

    int numofBits(int num)
    {
        int count = 0;
        while(num)
        {
            count += num&1;
            num >>=1;
        }
        return count;
    }
};
