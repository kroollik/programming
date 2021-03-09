num = int(input("1 - ввод параметров треугольника через длины сторон или 2 - ввод параметров через координаты вершин "))
if num == 1:
    a = float(input("Введите а = "))
    b = float(input("Введите b = "))
    c = float(input("Введите c = "))
    if a > 1000 or b > 1000 or c > 1000 or a <= 0 or b<=0 or c<=0:
        print("Ошибочный ввод")
    p = (a + b + c) / 2
    print("S =",((p * (p - a) * (p - b) * (p - c))**0.5))
elif num == 2:
    x1, y1 = map(int, input("Введите x1 и y1 ").split())
    x2, y2 = map(int, input("Введите x2 и y2 ").split())
    x3, y3 = map(int, input("Введите x3 и y3 ").split())
    a = (((x1 - x2)**2) + ((y1 - y2)**2))**0.5
    b = (((x2 - x3)**2) + ((y2 - y3)**2))**0.5
    c = (((x3 - x1)**2) + ((y3 - y1)**2))**0.5
    if a > 1000 or b > 1000 or c > 1000 or a <= 0 or b <= 0 or c <= 0:
        print ("Ошибочный ввод")
    p = (a + b + c) / 2
    print("S = ",((p * (p - a) * (p - b) * (p - c))**0.5))
elif num !=1 or num !=2:
    print ("Ошибочный ввод")

