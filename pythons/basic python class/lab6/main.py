from lab_module import *


while True:
    inputs = input('Please input your operation: ')
    inputs = inputs.split(' ')
    var_name = ''
    num = 0

    op = inputs[0]

    # using unpacking to get each parameters
    if op in [i for i in operation]:
        if len(inputs) == 1:  # printall, delall, rad, deg
            op = inputs[0]

        elif len(inputs) == 2:  # del, new, set, abs
            # unpacking inputs to op and name variables
            op = inputs[0]
            var_name = inputs[1]
            if is_number(var_name):
                data['ans'] = float(var_name)
                var_name = 'ans'

            elif var_name not in data:
                data[var_name] = 0

        elif len(inputs) == 3:  # add, mul, sub, div, mod, ind
            # unpacking ...
            op = inputs[0]
            var_name = inputs[1]
            if is_number(var_name):
                data['ans'] = float(var_name)
                var_name = 'ans'

            elif var_name not in data:
                data[var_name] = 0

            if not is_number(inputs[2]):
                if inputs[2] not in data:
                    data[inputs[2]] = 0

                num = data[inputs[2]]
            else:
                num = float(inputs[2])

    # handle operation logic
    if op == 'printall':
        print(data)

    elif op == 'delall':
        data.clear()
        print('delete all elements from data')

    elif op == 'rad':
        set_triangle_mode('rad')

    elif op == 'deg':
        set_triangle_mode('deg')

    # =====================================

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

    elif op == 'abs':
        abs(var_name)

    elif op == 'fac':
        fac(var_name)

    elif op == 'sin':
        sin(var_name)

    elif op == 'cos':
        cos(var_name)

    elif op == 'tan':
        tan(var_name)

    elif op == 'asin':
        asin(var_name)

    elif op == 'acos':
        acos(var_name)

    elif op == 'atan':
        atan(var_name)

    # =====================================

    elif op == 'add':
        add(var_name, num)

    elif op == 'mul':
        mul(var_name, num)

    elif op == 'sub':
        sub(var_name, num)

    elif op == 'div':
        div(var_name, num)

    elif op == 'mod':
        mod(var_name, num)

    elif op == 'ind':
        ind(var_name, num)

    elif op == 'end':
        break

    else:
        error_handle()

    print()
