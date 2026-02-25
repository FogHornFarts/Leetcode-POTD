class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                count++;
            }
            n = n / 2;
        }   
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){

                int bits1 = countBits(arr[j]);
                int bits2 = countBits(arr[j + 1]);
                if (bits1 > bits2) {
                    swap(arr[j], arr[j + 1]);
                }
                else if (bits1 == bits2 && arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        return arr;
    }
};