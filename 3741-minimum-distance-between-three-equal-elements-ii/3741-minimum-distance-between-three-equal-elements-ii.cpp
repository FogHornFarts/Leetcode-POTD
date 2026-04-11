class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<array<int, 2>> V(100001, {-1,-1});
        int ans = 1e9;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(V[x][0] == -1){
                V[x][0] = i;
            }else if(V[x][1] == -1){
                V[x][1] = i;
            }else{
                ans = min(ans, 2*(i-V[x][0]));
                V[x][0] = V[x][1];
                V[x][1] = i;
            }
        }
        return (ans == 1e9) ? -1: ans;
    }
};