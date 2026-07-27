class Solution {
public:
    int maxProduct(vector<int>& nums){
        int max = 0; 
        for (int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++) {
                int res = (nums[i]-1)*(nums[j]-1);
                if (res>max) {
                    max = res;
                }
            }
        }
        return max;
    }
};
