start, end = input().split()
start, end = int(start), int(end)

B_temp = end ** 0.5
B_temp = int(B_temp//1)

N_num = list(1 for _ in range(B_temp+1))
N_num[0] = 0
N_num[1] = 0
primes=[]

for i in range(2,B_temp+1):
    if N_num[i]:
        primes.append(i)
        for j in range(2*i, B_temp+1, i):
            N_num[j] = 0

ans = 0

for i in primes:
    j = 2
    while i**j <= end:
        if i**j >= start and i**j <= end:
            ans+=1
        j+=1

print(ans)