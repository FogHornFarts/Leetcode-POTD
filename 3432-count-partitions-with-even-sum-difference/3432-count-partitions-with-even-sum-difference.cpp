class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0;
        int sum1, sum2=0;
        for(int i=0;i<nums.size()-1;i++){
            sum1 = 0;
            sum2 += nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum1+=nums[j];
            }
            if((sum2-sum1)%2==0){
                count++;
            }
        }
        return count;
    }
};