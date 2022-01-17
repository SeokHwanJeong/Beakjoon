from collections import deque
N, K = input().split()
N, K = int(N), int(K)

numList = input().split()
#numList = list(map(int, numList))
ans = numList[:]
ans.sort()
dic = {''.join(numList):0}

def bfs():
    temp = numList[:]
    queue = deque()
    queue.append([temp, 0]);
    dic[''.join(temp)] = 1;
    while len(queue) != 0:
        now = queue.popleft()
        now_list = now[0]
        now_num = now[1]
        if now_list == ans:
            return now_num;
        for i in range(N-K+1):
            temp = list(map(str, now_list[i:K+i]))
            temp.reverse()
            #new = now_list[0:i] + temp + now_list[K+1:N]
            new = now_list[:]
            new[i:K+i] = temp[:]
            #print(temp)
            if dic.get(''.join(new))!=1:
                queue.append([new, now_num+1]);
                dic[''.join(new)]=1
    return -1
    
answer = bfs()
print(answer)