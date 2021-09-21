class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        n, m = len(matrix), len(matrix[0]) 
        self.horizontal = []
        self.vertical = [[0 for i in range(m)] for _ in range(n)]
        
        for row in matrix:
            acum = 0
            temp = []
            for val in row:
                acum += val
                temp.append(acum)
            self.horizontal.append(temp)
        
        
        for i in range(n):
            for j in range(m):
                if not i:
                    self.vertical[0][j] = matrix[0][j]
                else:
                    self.vertical[i][j] = matrix[i][j] + self.vertical[i - 1][j]
            
        
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        width = abs(col1 - col2)
        height = abs(row1 - row2)
        
        total = 0
        if width >= height:
            for i in range(row1, row2 + 1):
                minus = self.horizontal[i][col1 - 1] if col1 - 1 > -1 else 0
                total += self.horizontal[i][col2] - minus
        else:
            for i in range(col1, col2 + 1):
                minus = self.vertical[row1 - 1][i] if row1 - 1 > -1 else 0
                total += self.vertical[row2][i] - minus
        
        return total


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)