def backtrack(cur_a, cur_b, a, b, configurations):
    if (cur_a, cur_b) in configurations:
        return
    configurations.add((cur_a, cur_b))
    
    backtrack(0, cur_b, a, b, configurations)
    backtrack(cur_a, 0, a, b, configurations)
    
    backtrack(a, cur_b, a, b, configurations)
    backtrack(cur_a, b, a, b, configurations)

    pb = b - cur_b
    backtrack(cur_a - min(pb, cur_a), cur_b + min(pb, cur_a), a, b, configurations)
    pa = a - cur_a
    backtrack(cur_a + min(pa, cur_b), cur_b - min(pa, cur_b), a, b, configurations)


def main():
    a, b = map(int, input().split())

    configurations = set()
    backtrack(0, 0, a, b, configurations)

    print(len(configurations))
    print(sorted(list(configurations)))


main()