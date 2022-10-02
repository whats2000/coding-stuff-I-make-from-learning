our_string = 'Hello World!'

print(our_string.upper())  # 轉大寫

print(our_string.lower())  # 轉小寫

print(our_string.startswith('Hello'))  # 判斷字串是否以特定字串開始

print(our_string.endswith('World!'))  # 判斷字串是否以特定字串開始

print(our_string.endswith('world!'))  # Python is case-sensitive

print(our_string.replace('World', 'there'))

print(our_string.replace('o', '@', 1))  # only replace one o

print('  hello 123  '.lstrip())  # left strip

print('  hello 123  '.rstrip())  # right strip

print('  hello 123  '.strip())  # strip from both sides

print('  hello abc'.rstrip('cb'))  # strip c's and b's from right

print(our_string.ljust(30, '-'))

print(our_string.rjust(30, '-'))

print(our_string.center(30, '-'))

print(our_string.count('o'))  # it contains two o's

print(our_string.index('o'))  # the first o is our_string[4]

print(our_string.rindex('o'))  # the last o is our_string[7]

print('-'.join(['hello', 'world', 'test']))

print('hello-world-test'.split('-'))

print(our_string.upper()[3:].startswith('LO WOR'))  # combining multiple things

# check is palindrome word
our_string = str(input('Input a string : '))

if our_string == our_string[::-1]:
    print('Palindrome')
else:
    print('Not palindrome')

# replace function

our_string = 'Hello world'

print(our_string.replace('l', 's'))

# split function

our_string = 'Hi I am John'

print(our_string.split(' '))

# upper function

our_string = 'testing'

print(our_string.upper())
