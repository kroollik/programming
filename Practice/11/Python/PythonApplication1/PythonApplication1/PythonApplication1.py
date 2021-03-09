a = float(input("Введите число возводимое в степень: "))
b = int(input("Введите степень числа: "))
if b == 0:
    print("Результат работы программы:",1)
elif b == 1 or a == 1:
    print("Результат работы программы:",a)
k = 1
i = 1
if b > 0:  
    while i <= b:
        k *=a
        i +=1
    print(k)
elif b < 0:
    while i <= abs(b):
        k = k * (1/a)
        i +=1
    print(k)
    


