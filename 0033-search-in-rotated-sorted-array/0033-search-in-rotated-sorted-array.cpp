class Solution {
public:
    int search(vector<int>& nums, int target) {
        //rotate array by k towards left
        //then search for target, return key
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(nums[mid]<target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        /*
        int temp;
        int n=nums.size();
        for(int i=0,j=target-1;i<j;i++,j--){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for(int i=target,j=n-1;i<j;i++,j--){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for(int i=0,j=n-1;i<j;i++,j--){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        int target_index = -1;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){
                target_index = i;
            }
        }
        return target_index;
        */
        return -1;
    }
};