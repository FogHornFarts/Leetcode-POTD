class Solution {
    public int singleNumber(int[] nums) {
        // Intuition: pairs cancel with XOR, the single one remains
        int r = 0;
        for (int c : nums) {
            r ^= c;
        }
        return r;
    }
}