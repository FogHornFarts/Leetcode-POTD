class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return false;
        }
        int i=1;
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i==1){
            return false;
        }
        int decStart = i;
        while(i<n && nums[i]<nums[i-1]){
            i++;
        }
        if(i==decStart){
            return false;
        }
        int inc2Start = i;
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i==inc2Start){
            return false;
        }
        return i==n;
    }
};