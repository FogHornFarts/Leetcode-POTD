class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                b_count++;
            }else{
                ans = min(ans+1, b_count);
            }
        }
        return ans;
    }
};