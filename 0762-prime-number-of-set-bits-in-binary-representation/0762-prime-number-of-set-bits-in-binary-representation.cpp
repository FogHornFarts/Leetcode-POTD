class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i=left;i<=right;i++){
            int curr = i;
            if(curr==0){
                continue;
            }
            int counter = 0;
            while(curr>0){
                int rem = curr%2;
                if(rem==1){
                    counter++;
                }
                curr/=2;
            }
            if(isPrime(counter)){
                res++;
            }
        }
        return res;
    }
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};