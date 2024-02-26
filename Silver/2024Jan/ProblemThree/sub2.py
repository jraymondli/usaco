N = input()
S = list(set([int(x) for x in input().split()]))

U = min(S) // 4
if len(S) < 4:
    print(U*(U+1)//2)
    exit()

divs = set()
for i, s in enumerate(S[:4]):
    for _, r in enumerate(S[i:4]):
        diff = abs(s-r)
        for t in range(1, int(diff**(0.5) + 1)):
            if diff%t == 0:
                divs.add(t)
                divs.add(diff//t)

def test(L):
    if L > U:
        return False
    mods = set()
    for a in S:
        mods.add(a%L)
        if len(mods) >= 4:
            return False
    return True

print(len(divs))
print(sum([L for L in divs if test(L)]))


