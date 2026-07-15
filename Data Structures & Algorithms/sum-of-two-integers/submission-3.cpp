class Solution {
public:
    int getSum(int a, int b) {

        // we can xor two numbers to be able to add the numbers if there is any carry thwn we keep adding it

        int carry = ((a & b) << 1);
        a = a ^ b;
        cout<<a<<" "<<carry<<endl;
        while(carry)
        {
            int temp = ((a & carry) << 1);
            a = a ^ carry;
            carry = temp;
        }
        return a;
    }
};
