class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        n, m = len(horizontalCuts), len(verticalCuts)
        
        maxVer = max(abs(verticalCuts[0]), abs(w - verticalCuts[-1]))
        maxHor = max(abs(horizontalCuts[0]), abs(h - horizontalCuts[-1]))
        for i in range(n - 1):
            maxHor = max(maxHor, abs(horizontalCuts[i + 1] - horizontalCuts[i]))
            
        for i in range(m - 1):
            maxVer = max(maxVer, abs(verticalCuts[i + 1] - verticalCuts[i]))
            
        return (maxHor*maxVer)%( (10**9) + 7)