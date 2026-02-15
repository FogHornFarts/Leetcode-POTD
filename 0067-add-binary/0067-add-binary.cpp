class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int A = (i >= 0) ? (a[i] - '0') : 0;
            int B = (j >= 0) ? (b[j] - '0') : 0;
            int Cin = carry;

            // Full Adder Sum
            int Sum = A ^ B ^ Cin;

            // Full Adder Carry
            int Cout = ((A ^ B) & Cin) | (A & B);

            ans.push_back(Sum + '0');
            carry = Cout;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
