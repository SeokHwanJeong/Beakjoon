N, S, M = input().split()
N, S, M = int(N), int(S), int(M)

v_list = input().split()
v_list = list(map(int, v_list))

dp_list = [S]

for i in range(0,N):
    temp = []
    for j in dp_list:
        if 0 <= j-v_list[i]:
            if j-v_list[i] not in temp:
                temp.append(j-v_list[i])
        if j+v_list[i] <= M:
            if j+v_list[i] not in temp:
                temp.append(j+v_list[i])
    dp_list = temp[:]

dp_list.append(-1)
print(max(dp_list))