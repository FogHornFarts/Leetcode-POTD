class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int res =0;
        while(num>0){
            int digit = num%10;
            num/=10;
            if(temp%digit==0){
                res++;
            }
        }
        return res;
    }
};