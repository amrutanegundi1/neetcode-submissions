class Solution {
public:
    set<int> seen;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(seen.find(n) != seen.end())
        {
            return false;
        }
        seen.insert(n);

        int sum = 0;
        while(n)
        {
            int digit = n % 10;
            sum += (digit*digit);
            n = n/10;
        }
        return isHappy(sum);
    }
};
