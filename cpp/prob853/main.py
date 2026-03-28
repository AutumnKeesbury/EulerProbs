from sage.all import *

with open("orders.csv", "w") as f:
    f.write
for i in range(2, 1000):
    G = GL(2, Zmod(i))
    with open("orders.csv", "a") as f:
        f.write(str(i) + ", ")
        f.write(str(G.order()) + "\n")
