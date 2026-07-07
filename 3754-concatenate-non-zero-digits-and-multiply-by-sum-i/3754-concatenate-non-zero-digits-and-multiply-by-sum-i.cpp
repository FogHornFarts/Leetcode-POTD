class Solution {
public:
    long long sumAndMultiply(int n) {
        long long rev = 0;
        long long num = 0;
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                rev = rev * 10 + digit; 
                sum += digit;
            }
            n /= 10;
        }
        while (rev > 0) {
            num = num * 10 + (rev % 10);
            rev /= 10;
        }
        return num * sum;
    }
};