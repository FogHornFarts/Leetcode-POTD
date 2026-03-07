class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string doubled = s+s;
        string pattern1 = "";
        string pattern2 = "";
        for(int i=0;i<2*n;i++){
            pattern1+=(i%2==0) ? '0' : '1';
            pattern2+=(i%2==0) ? '1' : '0';
        }
        vector<int> diff1(2*n+1,0);
        vector<int> diff2(2*n+1,0);

        for(int i=0;i<2*n;i++){
            diff1[i+1] = diff1[i]+(doubled[i]!=pattern1[i] ? 1 : 0);
            diff2[i+1] = diff2[i]+(doubled[i]!=pattern2[i] ? 1 : 0);
        }
        int  minFlips = n;
        for(int i=0;i<n;i++){
            int flips1 = diff1[i+n] - diff1[i];
            int flips2 = diff2[i+n] - diff2[i];
            minFlips = min(minFlips, min(flips1, flips2));
        }
        return minFlips;
    }
};