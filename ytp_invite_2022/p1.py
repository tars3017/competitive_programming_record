text = input()
str2 = text.split(',')
arr = []
for i in str2:
    arr.append(int(i))
def step(x):
    if x == 1: 
        return 1
    elif x <= 0: 
        return 1
    return x*step(x-1)

total = 0
divide = 1
for i in arr:
    total += i
    divide *= step(i)
print(step(total) // divide)
