class Solution {
public:
    int tribonacci(int n) {
        int s1 = 0, s2 = 1, s3 = 1;
        if(n <= 1)
        {
            return n;
        }
        else if(n == 2)
        {
            return 1;
        }
        else
        {
            for(int i = 3; i <= n; i++)
            {
                int temp = s1 + s2 + s3;
                s1 = s2;
                s2 = s3;
                s3 = temp;
            }
        }
        return s3;
        
    }
};