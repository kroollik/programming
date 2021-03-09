i = 0
n = int(input("Введите целое число от 0 до 10^15: "))
if n > 0 and n < 10**15:
    while n > 0:
        n //=2
        i +=1
print (i)
