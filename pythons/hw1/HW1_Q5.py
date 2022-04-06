# print reverse number function
def rev_num_func(n):
    if n > 0:
        temp = n % 10
        print(temp, end='')
        rev_num_func(n // 10)


# input loop
while True:
    num = int(input('Please enter the numbers: \n'))

    # stop when number is less than zero
    if num < 0:
        break

    print('Reversed positive integer number:')

    rev_num_func(num)
    print('---------------------------------------------')
