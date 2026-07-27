class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        for(auto x: nums){
            q.push(x);
        }
        int p = q.top();
        q.pop();
        int s = q.top();
        int m = (p-1)*(s-1);
        return m;
    }
};