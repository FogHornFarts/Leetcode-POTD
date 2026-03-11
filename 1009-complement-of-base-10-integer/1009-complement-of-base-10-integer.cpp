class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0){
            return 1;
        }
        string bin_rev = "";
        while(n > 0){
            if(n % 2 == 0){
                bin_rev += '1';
            } else {
                bin_rev += '0';
            }
            n /= 2;
        }
        reverse(bin_rev.begin(), bin_rev.end());
        int res = 0;
        for(char c : bin_rev){
            res = res * 2 + (c - '0');
        }
        return res;
    }
};