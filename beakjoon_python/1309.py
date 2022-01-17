N = int(input())

temp = [[1], [1], [1]]

for i in range(1,N):
    temp[0].append((temp[1][i-1] + temp[2][i-1])%9901)
    temp[1].append((temp[0][i-1] + temp[2][i-1])%9901)
    temp[2].append((temp[0][i-1] + temp[1][i-1] + temp[2][i-1])%9901)

print((temp[0][N-1]+temp[1][N-1]+temp[2][N-1])%9901)