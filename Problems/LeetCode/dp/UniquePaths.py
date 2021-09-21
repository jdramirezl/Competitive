class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        res = [[-1 for i in range(n)] for j in range(m)]
        
        for i in range(1, m):
            res[i][0] = 1
        
        for j in range(1, n):
            res[0][j] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                res[i][j] = res[i - 1][j] + res[i][j - 1]
        
        return res[-1][-1] if n != 1 and m != 1 else 1