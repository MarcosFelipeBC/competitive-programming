t = int(input())
while (t > 0):
	x, n, m = input().split();
	x = int(x)
	n = int(n)
	m = int(m)
	flag = False;
	while (n > 0 and int(x/2) + 10 < x):
		x = int(x/2)
		x += 10;
		if(x <= 0):
			flag = True;
		n -= 1;

	while (m > 0):
		x -= 10;
		if(x <= 0):
			flag = True;
		m -= 1;
	print("YES" if flag else "NO")
	t -= 1;