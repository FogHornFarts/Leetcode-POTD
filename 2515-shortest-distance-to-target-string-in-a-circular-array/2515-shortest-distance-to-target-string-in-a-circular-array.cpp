class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        if (words[startIndex] == target){
            return 0;
        }
        int n = words.size();
        bool found = false;
        int countPrev = 0, countNext = 0;
        int prev = (startIndex - 1 + n)% n;
        int next = (startIndex + 1) % n;
        while (prev != startIndex) {
            countPrev++;
            if (words[prev] == target) {
                found = true;
                break;
            }
            prev = (prev - 1 + n) % n;
        }
        while (next != startIndex) {
            countNext++;
            if (words[next] == target) {
                found = true;
                break;
            }
            next = (next + 1) % n;
        }
        ans = min({ans, countPrev, countNext});
        return found ? ans : -1;
    }
};