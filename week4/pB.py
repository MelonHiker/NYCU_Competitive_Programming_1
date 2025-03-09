n, m = [int(x) for x in input().split()]

cnt = 0
while ((1 << cnt) < n):
    cnt += 1

if (cnt <= m):
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
