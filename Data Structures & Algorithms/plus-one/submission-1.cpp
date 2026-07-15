class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (!carry) break;
            int res = digits[i] + 1;
            if (res == 10) {
                carry = true;
                digits[i] = 0;
            } else {
                carry = false;
                digits[i] = res;
            }
        }
        if (carry) {
            digits.push_back(0);
            for (int i = digits.size() - 2; i >= 0; i--) {
                digits[i + 1] = digits[i];
            }
            digits[0] = 1;
        }
        return digits;
    }
};
