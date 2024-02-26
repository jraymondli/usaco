N = input()
S = list(set([int(x) for x in input().split()]))

U = min(S) // 4
if len(S) < 4:
    print(U*(U+1)//2)
    exit()

def test(L):
    mods = set()
    for a in S:
        mods.add(a%L)
        if len(mods) >= 4:
            return False
    return True

print(sum([L for L in range(1, U+1) if test(L)]))


