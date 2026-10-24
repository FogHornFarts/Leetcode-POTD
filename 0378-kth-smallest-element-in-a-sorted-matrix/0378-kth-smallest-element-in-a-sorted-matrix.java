class Solution {
    public static int counting(int matrix[][], int target) {
        int count = 0;
        int n = matrix.length;

        int row = 0;
        int col = n - 1;

        while (row < n && col >= 0) {

            if (matrix[row][col] <= target) {
                count += col + 1;
                row++;
            } else {
                col--;
            }
        }

        return count;
    }

    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = counting(matrix, mid);

            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}