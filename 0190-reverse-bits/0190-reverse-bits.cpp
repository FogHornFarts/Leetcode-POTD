class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        vector<int> bits;

        // Step 1: Extract all 32 bits (including leading zeros)
        for(int i = 0; i < 32; i++){
            bits.push_back(n % 2);
            n /= 2;
        }

        // Step 2: bits currently = reversed bits already (LSB → MSB)
        // So we can directly convert it to decimal.

        uint32_t ans = 0;
        uint32_t base = 1;

        for(int i = 31; i >= 0; i--){
            if(bits[i] == 1){
                ans += base;
            }
            base *= 2;
        }

        return ans;
    }
};
