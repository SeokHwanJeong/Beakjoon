N, M = input().split()
N, M = int(N), int(M)

graph = list()
for i in range(N):
    temp = []
    for j in range(N):
        if i==j:
            temp.append(0)
        else:
            temp.append(9999)
    graph.append(temp)

for i in range(M):
    a, b = input().split()
    a, b = int(a)-1, int(b)-1
    graph[a][b] = 1
    graph[b][a] = 1

def floyd(graph_1):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                graph_1[i][j] = graph_1[i][j] if graph_1[i][j] < graph_1[i][k] + graph_1[k][j] else graph_1[i][k] + graph_1[k][j]
    return graph_1

graph = floyd(graph)

sum_list = []
for i in range(N):
    sum = 0
    for j in range(N):
        sum += graph[i][j]
    sum_list.append(sum)

min = 0;
for i in range(N):
    if sum_list[i]<sum_list[min]:
        min = i

min +=1;
print(min)