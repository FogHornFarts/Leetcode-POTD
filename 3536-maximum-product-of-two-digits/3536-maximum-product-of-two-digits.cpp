class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while (n > 0) {
            int digit = n % 10;
            digits.push_back(digit);
            n /= 10;
        }
        int max_prod = 0;
        for (int i = 0; i < digits.size(); i++) {
            int product;
            for (int j = 0; j < digits.size(); j++) {
                if (i == j) {
                    continue;
                }
                product = digits[i] * digits[j];
                if (product >= max_prod) {
                    max_prod = product;
                }
            }
        }
        return max_prod;
    }
};