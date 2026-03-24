from math import sqrt

def Mu(n):
    size = n+1
    prime = [1] * size
    mu = [1] * size

    for i in range (2, size):
        if not prime[i]:
            continue
        mu[i] = -1
        for j in range (2, n // i + 1):
            prime[i*j] = 0
            mu[i*j] *= -1
        for j in range (1, n // (i*i) + 1):
            mu[i*j*i] = 0
    return mu

def square_free(n):
    sr = int(sqrt(n))
    mu = Mu(sr)

    s = 0
    for i in range (1, sr+1):
        s += mu[i] * (n // (i*i))
    return s

num = 2**50
print(square_free(num))