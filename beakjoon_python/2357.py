import sys
input = sys.stdin.readline

N, M = input().split()
N, M = int(N), int(M)

num = []
tree = [[0]]*400000

def init(node, start, end):
    if start==end:
        tree[node] = [num[start], num[end]] if num[start] < num[end] else [num[end], num[start]]
        return tree[node]
    mid = (start + end)//2
    a = init(node*2, start, mid)
    b = init(node*2+1, mid + 1, end)
    st = a[0] if a[0] < b[0] else b[0]
    ed = a[1] if a[1] > b[1] else b[1]
    
    tree[node] = [st, ed]
    return tree[node]


for i in range(N):
    num.append(int(input()))

def cal_val(node, start, end, fs, fe):
    if end < fs or fe < start:
        return [10000000000, -1]
    if fs <= start and end <= fe:
        return tree[node]
    mid = (start+end)//2
    a = cal_val(node*2, start, mid, fs, fe)
    b = cal_val(node*2+1, mid+1, end, fs, fe)
    st = a[0] if a[0] < b[0] else b[0]
    ed = a[1] if a[1] > b[1] else b[1]
    return [st, ed]

init(1, 0, N-1)

for i in range(M):
    a, b = input().split()
    a, b = int(a)-1, int(b)-1
    
    temp = cal_val(1, 0, N-1, a, b)
    
    print(temp[0], temp[1])