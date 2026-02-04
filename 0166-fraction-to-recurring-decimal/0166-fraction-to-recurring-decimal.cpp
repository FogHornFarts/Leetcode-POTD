class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) 
        {
            return "0";
        }
        string result;
        bool isNegative = (numerator < 0) ^ (denominator < 0);
        if (isNegative)
        {
             result += "-";
        }
        long long n = numerator;
        long long d = denominator;
        n = n < 0 ? -n : n;
        d = d < 0 ? -d : d;

        result += to_string(n / d);
        n %= d;
        if (n == 0) 
            return result;

        result += ".";
        vector<pair<long long, int>> remainders;

        while (n != 0) 
        {
            int pos = -1;
            for (int i = 0; i < remainders.size(); ++i) 
            {
                if (remainders[i].first == n) 
                {
                    pos = remainders[i].second;
                    break;
                }
            }
            if (pos != -1) 
            {
                result.insert(pos, "(");
                result += ")";
                break;
            }
            remainders.push_back({n, (int)result.size()});
            n *= 10;
            result += to_string(n / d);
            n %= d;
        }
        return result;
    }
};