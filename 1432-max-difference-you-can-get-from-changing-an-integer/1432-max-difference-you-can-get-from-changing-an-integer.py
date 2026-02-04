class Solution:
    def maxDiff(self, num: int) -> int:
        num_str = str(num)

        # Function to replace all occurrences of a digit x with y in a number
        def replace_digit(s, x, y):
            res = ''.join([y if ch == x else ch for ch in s])
            # Ensure the number doesn't start with '0' and is not zero
            if res[0] == '0':
                return -1
            return int(res)

        max_val = 0
        min_val = float('inf')

        for x in '0123456789':
            for y in '0123456789':
                replaced = replace_digit(num_str, x, y)
                if replaced != -1:
                    max_val = max(max_val, replaced)
                    min_val = min(min_val, replaced)

        return max_val - min_val
