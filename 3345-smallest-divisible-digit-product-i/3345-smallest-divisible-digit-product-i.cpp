class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; ; ++i) { 
            int temp = i;
            int product = 1;
            if (i == 0) {
                product = 0;
            } else {
                while(temp > 0){
                    int digit = temp % 10;
                    product *= digit; 
                    temp /= 10;
                }
            }
            if (product % t == 0) {
                return i; 
            }
        }
    }
};