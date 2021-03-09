
a = float(input("Введите число а "))
b = float(input("Введите число b "))
c = float(input("Введите число с "))
D = b*b - 4 * a * c
if a == 0 and b == 0 and c == 0: 
    print("Корнем уравнения является любое число")
elif a == 0 and b == 0:
    print("Нет корней")
elif a == 0:
    print("x = ",(-c)/b)
elif D < 0:
    print ("Нет действительных корней")
elif D == 0:
    print("x = ", (-b)/(2*a))
elif D > 0:
    print('x1 =', ((-b)+(D**0.5))/(2 * a))
    print('x2 =', ((-b)-(D**0.5))/(2 * a))
    

    
    
