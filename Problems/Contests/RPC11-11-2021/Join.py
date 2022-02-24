def main():

    g, b = map(int, input().split())
    games = []
    while g:
        p, s = map(int, input().split())
        games.append((p, s))

        g -= 1
    games.sort(key=lambda x: (x[0], -x[1]))
    ans = 0
    for x, y in games:
        if x <= b:
            b -= x
            ans += y

    print(ans)


main()