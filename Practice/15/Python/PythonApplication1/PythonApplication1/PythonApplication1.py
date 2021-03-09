def main():
    import random
    n = random.randint(1, 100)
    print ("Добро пожаловать! Попробуй угадать число от 0 до 100 за 5 попыток.")
    for i in range(5):
     f = int(input())
     if (f < n):
            print("Загаданное число больше")
     elif (f > n):
           print("Загаданное число меньше")
     elif (f == n):
          print("Поздравляю! Вы угадали")
    if (f!=n):
      print("Вы проиграли. Было загадано: ", n)
      one = int(input("Хотите начать сначала? (1 - ДА )"))
      if (one == 1):
          return main()
main()