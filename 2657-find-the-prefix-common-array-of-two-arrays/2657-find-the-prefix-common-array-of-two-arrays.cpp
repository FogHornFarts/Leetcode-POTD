class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), prefix = 0, i = 0;
        vector<int> ans(n);
        unordered_set<int> a, b;

        while(i < n) {
            int curr = 0;
            if(A[i] == B[i]) curr++;
            else {
                if(a.count(B[i])) curr++;
                if(b.count(A[i])) curr++;
            }

            ans[i] = prefix+curr;
            prefix = ans[i];

            a.insert(A[i]);
            b.insert(B[i]);

            i++;
        }

        return ans;
    }
};