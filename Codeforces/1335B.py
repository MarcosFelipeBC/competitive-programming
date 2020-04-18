t = int(input())
while (t > 0):
	n, a, b = input().split();
	n = int(n)
	a = int(a)
	b = int(b)
	ans = ""
	alpha = "abcdefghijklmnopqrstuvwxyz"
	for x in range(0, b):
		ans += alpha[x]

	sz = len(ans)
	while (sz < a):
		ans += ans[sz-1]
		sz += 1

	while (sz < n):
		ans += ans[sz-a]
		sz += 1
		
	print(ans)
	t -= 1