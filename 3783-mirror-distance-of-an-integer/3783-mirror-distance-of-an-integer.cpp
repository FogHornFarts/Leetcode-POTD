class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
    int reverse(int n){
        int reversed_num = 0;
        int digits;
        while(n>0){
            digits = n%10;
            reversed_num = (reversed_num*10) + digits;
            n/=10;
        }
        return reversed_num;
    }
};