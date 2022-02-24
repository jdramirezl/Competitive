from collections import defaultdict

def main():
    n = int(input())
    people = defaultdict(int)
    groups = n / 2
    if n%2!=0:
        print("impossible")
        return
    ta = 0
    tb = 0
    while n:
        a, b = map(int, input().split())
        ta += a
        tb += b
        people[(a, b)] += 1
        n -= 1
    aa = ta / groups
    bb = tb / groups
    for x, y in people.keys():
        if people[(aa-x, bb-y)] != people[(x, y)]:
            print("impossible")
            return
    print("possible")

main()