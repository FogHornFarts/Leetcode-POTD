class Solution {
public:
    string smallestPalindrome(string s) 
    {
        vector<int> t(26, 0);
        for (char c : s) {
            t[c - 'a']++;
        }
        string left = "";
        string middle = ""; 
        for (int i = 0; i < 26; i++) {
            int n = t[i]; 
            for (int j = 0; j < n / 2; j++) {
                left += char(i + 'a');
            } 
            if (n % 2 == 1 && middle.empty()) {
                middle += char(i + 'a');
            }
        } 
        string right = left;
        reverse(right.begin(), right.end());
        return left + middle + right;
    }
};