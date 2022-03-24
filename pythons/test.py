import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv('https://sololearn.com/uploads/files/titanic.csv')
# Plotting the adjusted line over the scattered values
y = np.linspace(0, 80, 100)  # Evenly spaced points (100) in a given interval (from 0 to 80)
x = (0.01549065 * y + 0.51037152) / 0.01615949  # X value taken from the line ecuation
plt.plot(x, y, '-b', label='')  # Plotting the line
plt.xlabel('Fare')
plt.ylabel('Age')
plt.scatter(df['Fare'], df['Age'], c=df['Survived'])  # plt.scatter(xAxis,yAxis,classes)
plt.grid()  # Grid over plotted image
plt.show()
