class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minval){
                minval = nums[i];
            }
        }
        return minval;
    }
};