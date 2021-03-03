import random

def is_int(s):
  while True :  
    try :
      int(s) 
      break
    except  ValueError:
      print("錯誤 未知字元 請重新輸入")
      s = input()
  return int(s)

guess = 0
minnum = is_int(input("請設定最小值 :"))
maxnum = minnum + 1
while True :
  maxnum = is_int(input("請設置最大值 :"))
  if maxnum > minnum :
    break
  else :
    print("錯誤 最大小於等於最小值 請重新輸入")

code = random.randint(minnum,maxnum)
guess -= minnum
while guess != code :
  print("請從",minnum,"~",maxnum,"選數字")
  guess = is_int(input("我猜 :"))
  if maxnum >= guess >= minnum and guess <= code :
    minnum = guess
  elif maxnum >= guess >= minnum and guess >= code:
    maxnum = guess
  else :
    print("錯誤 輸入範圍 請重新輸入")
print("猜中了")