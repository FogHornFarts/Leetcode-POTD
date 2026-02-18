class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary_str = bitset<32>(n).to_string();
        size_t first_one = binary_str.find_first_of('1');
        if (first_one == std::string::npos) {
            binary_str = "0"; 
        } else {
            binary_str = binary_str.substr(first_one);
        }
        for (size_t i = 0; i<binary_str.length()-1;++i) {
            if (binary_str[i] == binary_str[i + 1]) {
                return false; 
            }
        }
        return true;
    }
};