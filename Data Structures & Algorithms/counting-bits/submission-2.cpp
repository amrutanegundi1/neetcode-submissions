class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        result[0] = 0;
        int offset=1;
        for(int i = 1; i <= n; i++)
        {
            if(i == 2*offset)
            {
                offset = i;
            }
            result[i] = 1 + result[i-offset];
        }
        return result;
    }

    int numofBits(int num)
    {
        int count = 0;
        while(num)
        {
            count += 1;
            num &=num-1;
        }
        return count;
    }
};
