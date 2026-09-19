class Solution {
    public int missingNumber(int[] nums) {
        int res=0,i=0;
        for(i=0;i<nums.length;i++)
        {
            res = res^nums[i]^i;
        }

        return res^i;
    }
}