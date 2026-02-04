class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        MOD = 10**9+7

        max_n = n
        fact = [1] * (max_n + 1)
        inv_fact = [1] * (max_n + 1)

        for i in range(1,max_n+1):
            fact[i] = fact[i-1] * i % MOD
        
        inv_fact[max_n] = pow(fact[max_n], MOD - 2, MOD)
        for i in range(max_n - 1, -1, -1):
            inv_fact[i] = inv_fact[i+1] * (i+1) % MOD
        
        def comb(n,r):
            if r < 0 or r > n:
                return 0
            return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD

        result = m * comb(n-1,k) % MOD
        result = result * pow(m-1,n-1-k,MOD) % MOD

        return result        