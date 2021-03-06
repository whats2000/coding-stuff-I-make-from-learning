import numpy as np

def isInt(s,minNum,maxNum):
  while True :  
    try :
      int(s) 
      break
    except  ValueError:
      print("錯誤 未知字元 請重新輸入")
      s = input()
  return int(s)
			
data = []

times = isInt(input("請輸入資料數目 : "))

for t in range(times):
	data.append(isInt(input("請輸入第 "+str(t+1)+" 個數據 : ")))

print("平均值 : ", np.mean(data))
print("中位數 : ", np.median(data))
print("50%為 : :", np.percentile(data, 50))
print("25%為 : ", np.percentile(data, 25))
print("75%為 : ", np.percentile(data, 75))
print("平方合 : ", np.std(data))
print("標準差 : ", np.var(data))