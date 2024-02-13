def genarray(i, N, C, curscores):
    if curscores[i] != 0:
        if i == N: yield curscores
        else: yield from genarray(i + 1, N, C, curscores)
    else:
        for score in range(1, C + 1):
            curscores[i] = score
            if i == N: yield curscores
            else: yield from genarray(i + 1, N, C, curscores)
        curscores[i] = 0

t = int(input())

for test in range(t):
    N, Q, C = map(int, input().strip().split())
    c = [0] + [*map(int, input().strip().split())]
    constraints = [[*map(int, input().strip().split())] for _ in range(Q)]
    for curscores in genarray(1, N, C, c):
        for [a, h] in constraints:
            if max(curscores[: a + 1]) != max(curscores[:h]) or \
                curscores[h] <= max(curscores[: a + 1]):
                break
        else:
            print(*curscores[1:])
            break
    else:
        print(-1)

