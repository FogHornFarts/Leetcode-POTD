class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> valid;
        int cnt = 1;
        for(int i=1;i<(int)s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                valid.push_back(cnt);
                cnt = 1;
            }
        }
        valid.push_back(cnt);
        int ans = 0;
        for(int i=1;i<(int)valid.size();i++){
            ans+=min(valid[i-1],valid[i]);
        }
        return ans;
    }
};