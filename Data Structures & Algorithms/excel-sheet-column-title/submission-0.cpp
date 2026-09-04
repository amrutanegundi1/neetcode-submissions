class Solution {
public:
    string convertToTitle(int num) {
        string res;
        while(num)
        {
            if(num <= 26)
            {
                res = char('A' + (num - 1)) + res;
                break;
            }
            else
            {
                int rem = num % 26;
                res = char('A' + (rem - 1)) + res;
                num = num/26; 
            }
        }
        return res;
    }
};