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
    for i in range(1, N + 1):
        # Ensure that every j such that i < j < B[i] has B[j] = B[i]
        for j in range(i, B[i]):
            if B[j] != 0 and B[j] != B[i]:
                return print(-1)
            B[j] = B[i]

    for i in range(1, N + 1):
        if B[i] == 0:
            continue
        # calculate max before and max after
        mx_before = max(c[: i + 1])
        mx_after = max(c[: B[i]])

        # change max before such that mx_before = mx_after
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

    # Check that each element in the minimum sequence is at most C
    for i in range(1, N + 1):
        if c[i] > C:
            return print(-1)

    return print(*c[1:])


for _ in range(t):
    solve()


