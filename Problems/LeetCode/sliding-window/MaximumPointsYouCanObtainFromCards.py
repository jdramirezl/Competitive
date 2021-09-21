class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        
        window, ind = 0, 0
        for i in range(k):
            window += cardPoints[i]
            ind = i
        
        n = len(cardPoints)
        
        window2 = window
        for i in range(n - 1, n - k - 1, -1):
            window2 -= cardPoints[ind]
            ind -= 1
            window2 += cardPoints[i]
            window = max(window, window2)
        
        return window
            
        