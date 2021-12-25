num = input()
n = len(num)
pref = [0] * n
prefSum = 0
for i in range(len(num)):
    prefSum += ord(num[i]) - ord('0')
    pref[i] = prefSum

ans = ""
sum1 = 0
for i in range(n - 1, -1, -1):
    sum1 += pref[i]
    ans += chr(ord('0') + int(sum1 % 10))
    sum1 = int(sum1 / 10)

if (sum1 != 0):
    for i in str(sum1):
        ans += i

print(ans[::-1])