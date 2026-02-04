class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        result = set()
        key_indices = [j for j in range(len(nums)) if nums[j] == key]
        for j in key_indices:
            start = max(0, j-k)
            end = min(len(nums) - 1,j+k)
            for i in range(start,end+1):
                result.add(i)
        return sorted(result)