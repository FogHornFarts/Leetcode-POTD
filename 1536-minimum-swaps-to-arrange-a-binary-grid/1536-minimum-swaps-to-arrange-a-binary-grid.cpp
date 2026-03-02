class Solution {
public:
    int minSwaps(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> trailing(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailing[i] = count;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int pos = i;

            while (pos < n && trailing[pos] < required) {
                pos++;
            }
            if (pos == n) {
                return -1;
            }
            while (pos > i) {
                swap(trailing[pos], trailing[pos - 1]);
                swaps++;
                pos--;
            }
        }
        return swaps;
    }
};