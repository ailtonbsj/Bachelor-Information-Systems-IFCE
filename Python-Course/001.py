nk = "4 10"
n_str = "5 4 2 4"

[n, k] = map(lambda i: float(i), nk.split(' '))
n_arr = map(lambda i: float(i), n_str.split(' '))
n_arr.sort()

def greedy(acc, item):
    [outlay,pastry] = acc
    if outlay + item <= k:
        acc = [outlay + item, pastry + 1]
    return acc
[outlay,pastry] = reduce(greedy, n_arr,[0,0])

print("Total de pasteis: " + str(pastry))
print("Custos: " + str(outlay))
