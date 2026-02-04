class Solution:
    def minMaxDifference(self, num: int) -> int:
        num_str = str(num)
        
        # For maximum value - try replacing each digit with '9'
        max_val = num
        for d in num_str:
            if d != '9':
                max_candidate = int(num_str.replace(d, '9'))
                max_val = max(max_val, max_candidate)
                break  # Only one digit change allowed
        
        # For minimum value - try replacing each digit with '0'
        min_val = num
        for d in num_str:
            if d != '0':
                min_candidate = int(num_str.replace(d, '0'))
                min_val = min(min_val, min_candidate)
                break  # Only one digit change allowed

        return max_val - min_val
