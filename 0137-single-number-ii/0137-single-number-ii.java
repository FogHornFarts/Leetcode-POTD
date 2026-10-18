class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i: nums){
            map.put(i, map.getOrDefault(i,0) + 1);
        }
        int ans = 0;
        for(Map.Entry<Integer, Integer> hm : map.entrySet()){
            if(hm.getValue().equals(1)){
                ans = hm.getKey();
            }
        }
        return ans;
    }
}