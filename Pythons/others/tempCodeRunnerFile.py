import re

from numpy import double

# is_number() funtion from https://www.itread01.com/article/1533266784.html


def is_number(num):
    pattern = re.compile(r'^[-+]?[-0-9]\d*\.\d*|[-+]?\.?[0-9]\d*$')
    result = pattern.match(num)
    if result:
        return True

    else:
        return False


data = {
    'n1': 0,
    'n2': 10,
}

operation = ('printall',
             'delall',
             'del',
             'new',
             'set',
             'add',
             'mul',
             'sub',
             'div',
             'mod')

while True:
    inputs = input('Please input your operation: ')
    inputs = inputs.split(' ')
    var_name = ''
    num = 0

    op = inputs[0]

    # using unpacking to get each parameters
    if op in [i for i in operation]:
        if len(inputs) == 1:  # printall, delall
            op = inputs[0]

        elif len(inputs) == 2:  # del, new
            # unpacking inputs to op and name variables
            op = inputs[0]
            var_name = inputs[1]

        elif len(inputs) == 3:  # add, mul, sub, div, mod
            # unpacking ...
            op = inputs[0]
            var_name = inputs[1]
            if is_number(var_name):
                data['ans'] = double(var_name)
                var_name = 'ans'

            elif var_name not in data:
                data[var_name] = 0

            if not is_number(inputs[2]):
                if inputs[2] not in data:
                    data[inputs[2]] = 0

                num = data[inputs[2]]
            else:
                num = double(inputs[2])

    # handle operation logic
    if op == 'printall':
        print(data)

    elif op == 'delall':
        data.clear()
        print('delete all elements from data')

    elif op == 'del':
        if var_name in data:
            del data[var_name]
            print(f'delete {var_name}')
        else:
            print(f'{var_name} is not create')

    elif op == 'new':
        data[var_name] = 0
        print(f'create {var_name}')

    elif op == 'set':
        data[var_name] = num
        print(f'set {var_name} to {num}')

    elif op == 'add':
        # calculate
        temp_num = data[var_name]
        data[var_name] += num
        print(f'{temp_num} + {num} = {data[var_name]} (store to {var_name})')

    elif op == 'mul':
        # same as add
        temp_num = data[var_name]
        data[var_name] *= num
        print(f'{temp_num} * {num} = {data[var_name]} (store to {var_name})')

    elif op == 'sub':
        # calculate
        temp_num = data[var_name]
        data[var_name] -= num
        print(f'{temp_num} - {num} = {data[var_name]} (store to {var_name})')

    elif op == 'div':
        # same as add
        temp_num = data[var_name]
        data[var_name] /= num
        print(f'{temp_num} / {num} = {data[var_name]} (store to {var_name})')

    elif op == 'mod':
        # same as add
        temp_num = data[var_name]
        data[var_name] %= num
        print(f'{temp_num} % {num} = {data[var_name]} (store to {var_name})\n')

    elif op == 'end':
        break

    else:
        print('unknown command')
        for name in operation:
            print(f'Valid command : {name}')

    print()
