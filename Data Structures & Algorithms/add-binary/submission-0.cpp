class Solution {
   public:
    string addBinary(string a, string b) {
        int len1 = a.length(), len2 = b.length();

        if (len2 > len1) {
            string temp = b;
            b = a;
            a = temp;
            int len = len2;
            len2 = len1;
            len1 = len;
        }
        bool carry = false;
        int j = len1 - 1;
        for (int i = len2 - 1; i >= 0; i--, j--) {
            if (a[j] == b[i] && a[j] == '1') {
                if (carry) {
                    a[j] = '1';
                } else {
                    carry = true;
                    a[j] = '0';
                }
            } else if (a[j] == b[i] && a[j] == '0') {
                if (carry) {
                    a[j] = '1';
                    carry = false;
                }
            } else {
                if (carry) {
                    a[j] = '0';
                } else {
                    a[j] = '1';
                }
            }
        }
        if (carry) {
            for (j; j >= 0; j--) {
                if(carry)
                {
                    if(a[j] == '1')
                    {
                        a[j] = '0';
                    }
                    else
                    {
                        a[j] = '1';
                        carry = false;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if(carry)
        {
            a = '1' + a;
        }
        return a;
    }
};