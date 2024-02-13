
t = int(input())

def solve():
    N, Q, C = map(int, input().strip().split())
    B = [0] * (N + 1)
    c = [0] + [*map(int, input().strip().split())]
    assigned = [*map(bool, c)]

    # Initially choose 1 for every non-fixed element
    c = [score if score else 1 for score in c]

    for _ in range(Q):
        ai, hi = map(int, input().strip().split())
        B[ai] = hi

    # Ensure constraints for B
    curind = 1
    while curind <= N:
        i = curind
        # Ensure that every j such that i < j < B[i] has B[j] = B[i]
        while curind < B[i]:
            if B[curind] != 0 and B[curind] != B[i]:
                return print(-1)
            B[curind] = B[i]
            curind += 1
        curind = max(curind, i+1)

    mx_before = 0
    mx_after = 0
    i = 1
    while i <= N:
        # calculate max before and max after
        mx_before = max(mx_before, c[i])
        mx_after = max(mx_after, c[i])
        if B[i] == 0:
            i += 1
            continue
        mx_after = max(mx_after, *c[i:B[i]])
        
        # change mx_before such that mx_before = mx_after
        if mx_after > mx_before:
            for j in range(i, 0, -1):
                if B[j] != 0 and B[j] < B[i]:
                    return print(-1)
                if assigned[j]:
                    continue
                c[j] = mx_after
                break
            else:
                return print(-1)
            mx_before = mx_after

        if not assigned[B[i]]:
            c[B[i]] = mx_before + 1
        # check to make sure B[i] > mx_before
        if c[B[i]] <= mx_before:
            return print(-1)

        i = B[i]

    # Check that each element in the minimum sequence is at most C
    for i in range(1, N + 1):
        if c[i] > C:
            return print(-1)

    return print(*c[1:])

for _ in range(t):
    solve()


