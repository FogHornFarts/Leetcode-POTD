class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long sum = 0;
        int max = nums[0];
        int min = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }
            if(nums[i]<min){
                min = nums[i];
            }
        }
        for(int i=0;i<k;i++){
            sum+=max-min;
        }
        return sum;
    }
};