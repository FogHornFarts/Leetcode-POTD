#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zeros = 0;
        for (char c : s) {
            if (c == '0') zeros++;
        }
        if (zeros == 0) return 0;
        
        int ones = n - zeros;
        // try all possible numbers of operations from 1 to n
        for (int m = 1; m <= n; ++m) {
            long long totalFlips = 1LL * m * k;
            if (totalFlips < zeros) continue;               
            if ((totalFlips - zeros) % 2 != 0) continue;    
            
            long long diff = n - k;                       
            if (m % 2 == 0) {
                // even number of operations
                if (1LL * m * diff >= zeros) return m;
            } else {
                // odd number of operations
                if (1LL * m * diff >= ones) return m;
            }
        }
        return -1;
    }
};