


if __name__ == '__main__':

    line = input()
    n, q = line.split(' ')
    n = int(n)
    q = int(q)
    print(n, q)

    line = input()
    line_items = line.split(' ')
    array = [int(item) for item in line_items]
    print(array)

    sum_array = [0]
    sum = 0
    for i in range(n):
        sum += array[i]
        sum_array.append(sum)

    print(sum_array)

    for i in range(q):
        line = input()
        l, r = line.split(' ')
        l = int(l)
        r = int(r)

        print(sum_array[r] - sum_array[l])



