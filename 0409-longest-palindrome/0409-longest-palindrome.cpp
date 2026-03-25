class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};
        for(char c:s){
            freq[c]++;
        }
        int length = 0;
        bool hasOdd = false;
        for(int i=0;i<128;i++){
            if(freq[i]%2==0){
                length+=freq[i];
            }else{
                length+=freq[i]-1;
                hasOdd=true;
            }
        }
        if(hasOdd){
            length+=1;
        }
        return length;
    }
};