class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total, zero, ind = 1, 0, -1
        
        for i, n in enumerate(nums): 
            if n == 0:
                zero += 1
                ind = i
                continue
            total *= n
        
        if zero > 1:
            return [0 for n in nums]
        elif zero == 1:
            ans = [0 for i in nums]
            ans[ind] = total
            return ans
            
        ans = []
        for n in nums:
            total /= n
            ans.append(int(total))
            total *= n
        
        return ans