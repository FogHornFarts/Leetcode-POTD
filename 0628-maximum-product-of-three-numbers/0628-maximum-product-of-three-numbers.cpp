class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int prod1 = nums[0]*nums[1]*nums[2];
        int prod2 = nums[0]*nums[n-1]*nums[n-2];
        if(prod1>prod2){
            return prod1;
        }else{
            return prod2;
        }
    }
};