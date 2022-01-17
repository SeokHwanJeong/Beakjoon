N, T =  input().split()
N, T = int(N), int(T)

bus_list = []
for _ in range(N):
    temp = input().split()
    temp = list(map(int, temp))

    for i in range(temp[2]):
        bus_list.append(temp[0]+(temp[1]*i))

bus_list.sort()

ans = -1
for i in bus_list:
    if i>=T:
        ans = i-T
        break

print(ans)