n = int(input())
arr = []
arr.append(0)
arr.append(1)
now = 1
for i in range(2, n+1):
    tmp = arr[i-1] + 3 * now
    now = now * 4
    arr.append(tmp)

ans = 0
for i in range(1, n+1):
    ans += arr[i]

print(ans)
