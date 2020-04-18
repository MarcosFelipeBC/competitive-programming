t = int(input())
while (t > 0):
	n = int(input())
	if (n%2 == 1):
		n += 1
	print(int(n/2) - 1)
	t -= 1