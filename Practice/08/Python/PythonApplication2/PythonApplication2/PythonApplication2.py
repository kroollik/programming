a = int(input("Введите число a: "))
c = str(input("Введите знак "))
b = int(input("Введите число b: "))
if (b == 0):
    print("Ошибка, деление на 0")
elif (c == '//'):
    print ("a // b =",a//b)
elif (c == '-'):  
    print("a - b =",a-b)
elif (c == '*'):
    print("a * b =", a*b) 
else:
    print ("a // b =",a//b)

        