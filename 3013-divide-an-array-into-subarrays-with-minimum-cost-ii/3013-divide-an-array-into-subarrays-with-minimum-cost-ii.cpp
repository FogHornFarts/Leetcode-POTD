class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long sum = 0, ans = LLONG_MAX;

        priority_queue<int> small; // k-1 smallest (max heap)
        priority_queue<int, vector<int>, greater<int>> large;
        unordered_map<int,int> lazy;
        int smallSize = 0;

        auto clean = [&](auto &pq) {
            while (!pq.empty() && lazy[pq.top()]) {
                lazy[pq.top()]--;
                pq.pop();
            }
        };

        // initial window
        for (int i = 1; i <= dist + 1; i++)
            large.push(nums[i]);

        while (smallSize < k - 1) {
            int x = large.top(); large.pop();
            sum += x;
            small.push(x);
            smallSize++;
        }

        ans = sum;

        for (int r = dist + 2; r < n; r++) {
            int add = nums[r];
            int rem = nums[r - (dist + 1)];

            clean(small);
            clean(large);

            // add
            if (!small.empty() && add <= small.top()) {
                sum += add;
                small.push(add);
                smallSize++;
            } else {
                large.push(add);
            }

            // remove (lazy)
            lazy[rem]++;
            if (!small.empty() && rem <= small.top()) {
                sum -= rem;
                smallSize--;
            }

            clean(small);
            clean(large);

            // rebalance
            while (smallSize < k - 1) {
                int x = large.top(); large.pop();
                sum += x;
                small.push(x);
                smallSize++;
                clean(large);
            }

            while (smallSize > k - 1) {
                int x = small.top(); small.pop();
                sum -= x;
                large.push(x);
                smallSize--;
                clean(small);
            }

            ans = min(ans, sum);
        }

        return nums[0] + ans;
    }
};
