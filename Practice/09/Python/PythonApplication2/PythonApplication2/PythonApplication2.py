h1,m1 = map(int,input().split(':'))
h2,m2 = map(int,input().split(':'))
if h1 < 0 or h1 > 24 or m1 < 0 or m1 > 60:
    print("Ошибка ввода")
elif h2 < 0 or h2 > 24 or m2 < 0 or m2 > 60:
    print("Ошибка ввода")
elif (((h2 - h1 == 0) and (m2 - m1 <= 15)) or ((h2 - h1 == 1) and (m2 - m1 == -45)) or ((h2 - h1 == -23) and (m2 - m1 == -45))):
    print ("Встреча состоится")
else:
    print ("Встреча не состоится")

    
