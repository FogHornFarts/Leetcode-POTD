class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l = 0;
        int r = 0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L'){
                l++;
            }else if(moves[i]=='R'){
                r++;
            }
        }
        if(l<r){
            r = n-l;
        }else{
            l = n-r;
        }
        return abs(l-r);
    }
};