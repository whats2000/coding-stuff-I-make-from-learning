names = ['wub_wub', 'heels3', 'RubyPinch', 'go|fish', 'Nitori']

# remove function
names.remove('heels3')  # sorry heels3
names.remove('go|fish')  # and sorry go|fish

print(names)

# remove function only remove first one
names = ['heels3', 'go|fish', 'heels3']

names.remove('heels3')

print(names)

# append function
names.append('Aku')  # let's add me here

print(names)

# extend function
names.extend(['go|fish', 'heels3'])  # wb guys

print(names)

# copy operation
a = [1, 2, 3]
b = a
b.append(4)
print('a =', a)    # a所指向的值也被改動了

a = [1, 2, 3]

b = a.copy()

print('b is a =', b is a)

b.append(4)

print('a =', a)

print('b =', b)

