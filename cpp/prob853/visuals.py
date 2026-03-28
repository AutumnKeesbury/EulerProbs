import matplotlib.pyplot as plt
import csv
x = []
y = []

with open('orders.csv', 'r') as file:
    plots = csv.reader(file, delimiter=',')

    for row in plots:
        x.append(row[0])
        y.append(row[1])

fig, ax = plt.subplots(layout = 'constrained')

ax.set_xticks([])
ax.set_yticks([])
ax.scatter(x,y,s=0.1)
fig.show()