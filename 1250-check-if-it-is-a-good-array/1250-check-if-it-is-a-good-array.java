class Solution {
    public boolean isGoodArray(int[] nums) {

        int g = nums[0];
        for (int x : nums) {
            while (x > 0) {
                int temp = g % x;
                g = x;
                x = temp;
            }
            if (g == 1) {
                return true;
            }
        }
        return g == 1;
    }
}