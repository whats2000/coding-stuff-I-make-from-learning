# 有4個數字1,2,3,4，印出所有互不相同且無重複的三位數(順序不同算不同)
inp_list = [1, 2, 3, 4]
for i in range(1, 5):
    for j in range(1, 5):
        for k in range(1, 5):
            if (i != k) and (i != j) and (i != j):
                print(i, j, k)

print()

# 輸出99乘法表
for i in range(1, 10, 1):
    for j in range(1, i + 1, 1):
        print(f'{i}*{j} = {i * j}', end=' ')

    print()

print()

# 印出所有的"水仙花數"，水仙花數是指一個三位數，其每個位數的三次方和等於該數本身，例如153是一個水仙花數，因為153=1的三次方＋5的三次方＋3的三次方
print([i for i in range(100, 1000, 1) if (i // 100) ** 3 + ((i // 10) % 10) ** 3 + (i % 10) ** 3 == i])

print()

# 一個數如果恰好等於他的因數之和，這個數稱為"完數"，例如6=1＋2＋3，找出1000內所有完數
for i in range(1, 1001):
    total = 0
    for j in range(1, i):
        if i != j and i % j == 0:
            total += j

    print(f'{i}\n' if (total == i) else '', end='')

print()

# 一球從100公尺高度自由落下，每次落地後反彈高度為原高度的一半，之後再落下，求第10次落地時共經過多少公尺?，第10次反彈多高?
total = 0
height = 100

for i in range(10):
    total += height
    height /= 2
    total += height

print(f'10時落地高 : {total - height}\n第10次高度 : {height}')

print()

# 有兩個3X3的矩陣如下，根據對應的位置相加兩個矩陣
X = [[12, 7, 3],
     [4, 5, 6],
     [7, 8, 9]]

Y = [[5, 8, 1],
     [6, 7, 3],
     [4, 5, 9]]

Z = [[0]*3 for _ in range(3)]

for i in range(3):
    for j in range(3):
        Z[i][j] = X[i][j] + Y[i][j]

print(Z)
