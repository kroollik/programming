l2, l1, r2, r1, s = input().split()
if l1 < r1:
    x1 = l1
else:
    x1 = r1
if int(l2) + int(x1) == int(s):
    print(x1,l2)
elif int(r2) + int(x1) == int(s):
    print(x1,r2)
else:
    print(-1)
