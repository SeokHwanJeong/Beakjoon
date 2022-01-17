N = int(input())

tri_list = []
dp_list = []
for i in range(N):
    temp = input().split()
    temp = list(map(int, temp))
    tri_list.append(temp)

for i in range(1, N):
    index = 0
    for j in tri_list[i]:
        if index == 0:
            tri_list[i][index] += tri_list[i-1][index]
        elif index == i:
            tri_list[i][-1] += tri_list[i-1][-1]
        else:
            if tri_list[i][index] + tri_list[i-1][index-1] >= tri_list[i][index] + tri_list[i-1][index]:
                tri_list[i][index] += tri_list[i-1][index-1]
            else:
                tri_list[i][index] += tri_list[i-1][index]
        index+=1
        
ans = max(tri_list[N-1])

print(ans)
