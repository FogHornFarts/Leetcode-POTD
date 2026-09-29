class Solution {
    public int sumFourDivisors(int[] nums) {
        int res = 0;

        for (int num : nums) {
            int cnt = 2;               // 1 and num
            int sum = 1 + num;

            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    int other = num / d;

                    if (d == other) {
                        cnt++;
                        sum += d;
                    } else {
                        cnt += 2;
                        sum += d + other;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4) res += sum;
        }

        return res;
    }
}