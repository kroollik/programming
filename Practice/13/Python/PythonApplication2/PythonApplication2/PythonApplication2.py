n = int(input("Введите целое число от 2 до 10^9: "))
if n > 1 and n <= 10**9:
    if ((n % 2 == 0) or (n % 3 == 0) or (n % 5 == 0) or (n % 7 == 0) and ((n != 2) and (n != 3) and (n != 5) and (n != 7))):
        print("Составное")
    else:
        print("Простое")
