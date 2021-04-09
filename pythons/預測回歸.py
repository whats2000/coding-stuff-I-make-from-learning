from sklearn.linear_model import LogisticRegression
import numpy as np

n = int(input('請輸入矩陣數量 : '))
X = []
for i in range(n):
    X.append([float(x) for x in input('請輸入矩陣').split()])
y = [int(x) for x in input('請輸入判定布林值(0/1) : ').split()]
datapoint = [float(x) for x in input('請輸入預測矩陣 : ').split()]

model = LogisticRegression()
model.fit(X, y)

pre_datapoint = model.predict(np.array(datapoint).reshape(1, -1))

print('預測布林值為 : ', end='')
print(int(pre_datapoint))
