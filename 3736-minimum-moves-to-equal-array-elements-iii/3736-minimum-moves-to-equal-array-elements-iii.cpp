class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = nums[nums.size()-1];
        int counter = 0;
        for(int i=0;i<nums.size()-1;i++){
            int diff = max - nums[i];
            counter+=diff;
        }
        return counter;
    }
};