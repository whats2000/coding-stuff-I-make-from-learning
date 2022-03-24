import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('https://sololearn.com/uploads/files/titanic.csv')
plt.scatter(data['Age'], data['Fare'], c=data['Pclass'])
plt.xlabel('Age')
plt.ylabel("Fare")
plt.show()
