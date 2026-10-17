class Solution {
    public String frequencySort(String s) {
        int[][] x = new int[130][2];
        for (int i = 0; i < s.length(); i++) {
            x[s.charAt(i)][0]++;
        }
        for (int i = 0; i < 130; i++) x[i][1] = i;
        Arrays.sort(x, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));
        StringBuilder t = new StringBuilder();
        for (int i = 129; i >= 0; i--) {
            while (x[i][0] != 0) {
                t.append((char) x[i][1]);
                x[i][0]--;
            }
        }
        return t.toString();
    }
}