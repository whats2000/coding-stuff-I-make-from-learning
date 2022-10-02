# convert 2D array to 1D
before = [[1, 2], [3, 4], [5, 6]]
after = []
for number in before:
    for number1 in number:
        after.append(number1)

print(after)

print()

# sum of the list
input_num = ['1', '2', '3']

num_sum = 0

for num in input_num:
    num_sum += int(num)

print('sum = ', num_sum)

print()

# will output
# 1
# 1 2
# 1 2 3
# 1 2 3 4
# 1 2 3 4 5
for i in range(1, 6, 1):
    for j in range(1, i + 1, 1):
        print(j, end='')
    print()

print()

# output upside down base on input
row = int(input('Input row : '))

for i in range(1, row + 1, 1):
    for j in range(i, row + 1, 1):
        print(j, end='')
    print()

print()

# count number digit
count = 0

num = int(input('Enter a int : '))

while num > 0:
    num //= 10

    count += 1

print('count = ', count)

print()

# zip output
uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
lowercase = 'abcdefghijklmnopqrstuvwxyz'

for upper, lower in zip(uppercase, lowercase):
    print(upper, lower)

print()

# prime number
prime_num = []

for i in range(2, 101):
    for j in range(2, i):
        if i % j == 0:
            break
    else:
        prime_num.append(i)

print(prime_num)

print()

# fibonacci
a = 1
b = 1

for i in range(2, 10):
    a += b
    a, b = b, a

print(b)

print()

# reverse input
num = input('Input a int : ')

for n in range(len(num) - 1, -1, -1):
    print(num[n], end='')
