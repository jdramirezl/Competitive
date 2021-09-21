class Solution:
    def floodFill(self, image, sr, sc, newColor):
        if image[sr][sc] == newColor: return image
        moves = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        temp = image[sr][sc]
        image[sr][sc] = newColor
        for move in moves:
            nx = sr + move[0]
            ny = sc + move[1]
            if len(image) > nx >= 0 and len(image[0]) > ny >= 0 and image[nx][ny] == temp:
                Solution.floodFill(self, image, nx, ny, newColor)
                
        return image


#{ 
#  Driver Code Starts


if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        image = []
        for _ in range(n):
            image.append(list(map(int, input().split())))
        sr, sc, newColor = input().split()
        sr = int(sr); sc = int(sc); newColor = int(newColor);
        obj = Solution()
        ans = obj.floodFill(image, sr, sc, newColor)
        for _ in ans:
            for __ in _:
                print(__, end = " ")
            print()

# } Driver Code Ends