def sieve(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
            
        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
                
            # Update all multiples of p
            for i in range(p ** 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False
    
    primes = []
    for p in range(n + 1):
        if prime[p]:
            primes.append(p)
    
    ans=[]
    ans.append(3)
    for i in range(1, len(primes)):
        if primes[i - 1] == primes[i] - 2:
            if(ans[-1] != primes[i - 1]):
                ans.append(primes[i - 1])
            ans.append(primes[i])

    
    return ans

nums = sieve(pow(10, 6))

t = int(input())

while t:
    n = int(input())
    l, r = 0, len(nums) - 1
    while l + 1 < r:
        m = (l+r)//2
        if n < nums[m]:
            r = m
        else:
            l = m
    dl = abs(nums[l]-n)
    dr = abs(nums[r]-n)
    if dl==dr or dr < dl:
        print(nums[r])
    else:
        print(nums[l])
    t -= 1