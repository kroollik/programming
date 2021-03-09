from array import *
f = 0;
n = int(input());
t = input().split(' ');
for f in range (n):
    a = t[f];
    if ( (a[0] == 'a') & (a[4] == '5') & (a[5] == '5') & (a[6] == '6') & (a[7] == '6') & (a[8] == '1') ):
        print (a + " ");
        w = 1;
if w == 0:
	print (-1);
