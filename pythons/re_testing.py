import re

test = input("請輸入字串 : ")

test.encode('unicode-escape').decode().replace('\\\\', '\\')

print("輸入為 : "+test)

if re.match(test, "a"):
    print(test + " Match 1")

if re.match(test, "aa"):
    print(test + " Match 2")

if re.match(test, "aaaa"):
    print(test + " Match 3")
