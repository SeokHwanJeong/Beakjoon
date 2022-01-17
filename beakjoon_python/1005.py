from collections import deque

T = int(input())
require_order = []
order_value = []
order_check = []
order_left = []

def find_maxval(now):
    max_val = 0
    for i in require_order[now][1]:
        if order_value[i] > max_val:
            max_val = order_value[i]
    return max_val

def fun(st, de):
    queue = deque()
    queue.append([st, 0])
    while(len(queue)!=0):
        now = queue.popleft()
        max_val= find_maxval(now[0])
        if now[0] == de:
            return max_val+now[1]+order_value[now[0]]
        for i in require_order[now[0]][0]:
            if order_check[i]:
                queue.append([i, max_val+now[1]])
                order_check[i] = 0
    return -1


for _ in range(T):
    require_order = []
    order_value = []
    order_check = []
    order_left = []
    N, K = input().split()
    N, K = int(N), int(K)
    order_check = [1 for i in range(N)]
    for i in range(N):
        require_order.append([[], []])
    order_value = input().split()
    order_value = list(map(int, order_value))
    for i in range(K):
        st, de = input().split()
        st, de = int(st)-1, int(de)-1
        require_order[st][0].append(de)
        require_order[de][1].append(st)
        require_order[st][0].sort()
        require_order[de][1].sort()
    final_destination = int(input())-1

    for i in require_order:
        index = 0
        if len(i[1]) == 0:
            st = index
            break
        index+=1

    
    print("require_order", require_order)
    print("order_value", order_value)
    print("order_check", order_check)

    ans = fun(st, final_destination)

    print(ans)