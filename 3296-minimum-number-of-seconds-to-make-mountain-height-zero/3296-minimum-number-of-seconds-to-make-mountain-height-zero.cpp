using ll = long long;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll lo = 1, hi=1e16;
        while(lo<hi){
            ll mid = (lo+hi)/2;
            ll tot = 0;
            for(int t:workerTimes){
                tot+=(ll)(sqrt(2.0*mid/t + 0.25)-0.5);
                if(tot>=mountainHeight){
                    break;
                }
            }
            if(tot>=mountainHeight){
                hi=mid;
            }else{
                lo = mid+1;
            }
        }
        return lo;
    }
};