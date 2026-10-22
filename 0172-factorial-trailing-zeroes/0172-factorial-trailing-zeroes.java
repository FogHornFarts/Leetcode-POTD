class Solution {
    public int trailingZeroes(int n) {
        int ans = Math.floorDiv(n, 5);
        ans += Math.floorDiv(n, 25);
        ans += Math.floorDiv(n, 125);
        ans += Math.floorDiv(n, 625);
        ans += Math.floorDiv(n, 3125);
        
        
        return ans;
    }
}