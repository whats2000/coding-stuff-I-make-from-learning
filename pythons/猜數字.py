import random


def is_int(s):
    while True:
        try:
            int(s)
            break
        except  ValueError:
            print("錯誤 未知字元 請重新輸入")
            s = input()
    return int(s)


guess = 0
min_num = is_int(input("請設定最小值 :"))
max_num = min_num + 1
while True:
    max_num = is_int(input("請設置最大值 :"))
    if max_num > min_num:
        break
    else:
        print("錯誤 最大小於等於最小值 請重新輸入")

code = random.randint(min_num, max_num)
guess -= min_num
while guess != code:
    print("請從", min_num, "~", max_num, "選數字")
    guess = is_int(input("我猜 :"))
    if max_num >= guess >= min_num and guess <= code:
        min_num = guess
    elif max_num >= guess >= min_num and guess >= code:
        max_num = guess
    else:
        print("錯誤 輸入範圍 請重新輸入")
print("猜中了")
