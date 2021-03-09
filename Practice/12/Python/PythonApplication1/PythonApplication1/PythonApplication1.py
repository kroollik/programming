i = 1
f = 1
n = int(input("Введите целое число от 0 до 10^9: "))
if n > 0 and n < 10**9:
    while i <= n:
        f = f * i
        i +=1
print (f)

