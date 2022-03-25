import sys
input = sys.stdin.readline

N, M = input().split()
N, M = int(N), int(M)

num = []
tree = [[0]]*400000

def init(node, start, end):
    if start==end:
        tree[node] = num[start] if num[start] < num[end] else num[end]
        return tree[node]
    mid = (start + end)//2
    a = init(node*2, start, mid)
    b = init(node*2+1, mid + 1, end)
    tree[node] = a if a < b else b

    return tree[node]


for i in range(N):
    num.append(int(input()))

def cal_val(node, start, end, fs, fe):
    if end < fs or fe < start:
        return 10000000000
    if fs <= start and end <= fe:
        return tree[node]
    mid = (start+end)//2
    a = cal_val(node*2, start, mid, fs, fe)
    b = cal_val(node*2+1, mid+1, end, fs, fe)
    temp = a if a < b else b
    return temp

init(1, 0, N-1)

for i in range(M):
    a, b = input().split()
    a, b = int(a)-1, int(b)-1
    
    print(cal_val(1, 0, N-1, a, b))