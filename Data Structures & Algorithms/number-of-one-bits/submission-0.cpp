class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t test = 1;
        int counter = 0;
        for(int i = 0; i <32; i++)
        {
            counter += ((n & test)>0);
            test = test<<1;
        }
        return counter;
    }
};
