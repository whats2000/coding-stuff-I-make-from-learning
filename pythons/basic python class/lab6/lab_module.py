import math

data = {
    'n1': 0,
    'n2': 10,
}

operation = ('printall',
             'delall',
             'rad',
             'deg',

             'del',
             'new',
             'set',
             'abs',
             'fac',
             'sin',
             'cos',
             'tan',
             'asin',
             'acos',
             'atan',

             'add',
             'mul',
             'sub',
             'div',
             'mod',
             'ind')

triangle_mod = 'rad'


def is_number(num):
    try:
        float(num)
    except ValueError:
        return False

    return True


def set_triangle_mode(mode: str):
    global triangle_mod
    triangle_mod = mode
    print(f'set to {triangle_mod}')


def abs(var_name):
    temp_num = data[var_name]
    data[var_name] = abs(data[var_name])
    print(f'|{temp_num}| = {data[var_name]} (store to {var_name})')


def fac(var_name):
    temp_num = data[var_name]
    data[var_name] = math.factorial(int(data[var_name]))
    print(f'{temp_num}! = {data[var_name]} (store to {var_name})')


def sin(var_name):
    temp_num = data[var_name]
    if triangle_mod == 'deg':
        data[var_name] = math.radians(data[var_name])

    data[var_name] = math.sin(data[var_name])
    print(
        f'sin({temp_num}) = {data[var_name]} (store to {var_name}, mode : {triangle_mod})')


def cos(var_name):
    temp_num = data[var_name]
    if triangle_mod == 'deg':
        data[var_name] = math.radians(data[var_name])

    data[var_name] = math.cos(data[var_name])
    print(
        f'cos({temp_num}) = {data[var_name]} (store to {var_name}, mode : {triangle_mod})')


def tan(var_name):
    temp_num = data[var_name]
    if triangle_mod == 'deg':
        data[var_name] = math.radians(data[var_name])

    data[var_name] = math.tan(data[var_name])
    print(
        f'tan({temp_num}) = {data[var_name]} (store to {var_name}, mode : {triangle_mod})')


def asin(var_name):
    temp_num = data[var_name]

    data[var_name] = math.asin(data[var_name])

    if triangle_mod == 'deg':
        data[var_name] = math.degrees(data[var_name])

    print(
        f'asin({temp_num}) = {data[var_name]} (store to {var_name}, mode : {triangle_mod})')


def acos(var_name):
    temp_num = data[var_name]

    data[var_name] = math.acos(data[var_name])

    if triangle_mod == 'deg':
        data[var_name] = math.degrees(data[var_name])

    print(
        f'acos({temp_num}) = {data[var_name]} (store to {var_name}, mode : {triangle_mod})')


def atan(var_name):
    temp_num = data[var_name]

    data[var_name] = math.atan(data[var_name])

    if triangle_mod == 'deg':
        data[var_name] = math.degrees(data[var_name])

    print(
        f'atan({temp_num}) = {data[var_name]} (store to {var_name}, mode : {triangle_mod})')


def add(var_name, num: float):
    # calculate
    temp_num = data[var_name]
    data[var_name] += num
    print(f'{temp_num} + {num} = {data[var_name]} (store to {var_name})')


def mul(var_name, num: float):
    # same as add
    temp_num = data[var_name]
    data[var_name] *= num
    print(f'{temp_num} * {num} = {data[var_name]} (store to {var_name})')


def sub(var_name, num: float):
    # calculate
    temp_num = data[var_name]
    data[var_name] -= num
    print(f'{temp_num} - {num} = {data[var_name]} (store to {var_name})')


def div(var_name, num: float):
    # same as add
    temp_num = data[var_name]
    data[var_name] /= num
    print(f'{temp_num} / {num} = {data[var_name]} (store to {var_name})')


def mod(var_name, num: float):
    # same as add
    temp_num = data[var_name]
    data[var_name] %= num
    print(f'{temp_num} % {num} = {data[var_name]} (store to {var_name})\n')


def ind(var_name, num: float):
    # same as add
    temp_num = data[var_name]
    data[var_name] **= num
    print(f'{temp_num} ^ {num} = {data[var_name]} (store to {var_name})\n')


def error_handle():
    print('unknown command')
    for name in operation:
        print(f'Valid command : {name}')
