class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> addr = new ArrayList<Integer>();

        backtrack(1, n, k , res, addr);
        return res;
    }
    public List<List<Integer>> backtrack(int start, int n, int k, List<List<Integer>> res, List<Integer> addr){
        if(addr.size()==k){
            res.add(new ArrayList<>(addr));
            return res;
        }
        int r = k - addr.size();
        for(int i=start;i<=n-r+1;i++){
            addr.add(i);
            backtrack(i+1, n, k, res, addr);
            addr.remove(addr.size() - 1);
        }
        return res;
    }
}