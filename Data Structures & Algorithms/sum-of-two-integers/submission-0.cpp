class Solution {
public:
    int getSum(int a, int b) {

        int sum = a ^ b;
        int carry = (a & b) << 1;
        while(carry)
        {
            int temp = (sum & carry) << 1;
            sum = sum ^ carry;
            carry = temp;
        } 
        return sum;
        
    }
};
