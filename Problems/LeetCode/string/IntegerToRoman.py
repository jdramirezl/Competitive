class Solution:
    def intToRoman(self, num: int) -> str:
        el = [["IX", "IV", "V", "I"], ["XC", "XL", "L", "X"], ["CM", "CD", "D", "C"], [".",".",".","M"]]
        
        res = ""
        size = len(str(num))-1
        pos = 0
        num = str(num)
        
        for i in range (size, -1, -1):
            temp = int(num[i])
            print("num size", num[i])
            if temp == 9:
                res = el[pos][0]+res
            elif temp == 4:
                res = el[pos][1]+res
            elif temp >= 5:
                print(temp-5)
                res = el[pos][2] + el[pos][3]* (temp-5) + res 
            elif temp > 0:
                res = el[pos][3]* temp + res
            
            pos += 1
        
        return res