import sys
from typing import DefaultDict
input = sys.stdin.readline

N, M = input().split()
N, M = int(N), int(M)

num = [0] * (N+1)
tree = [0] * 4000000

def modify_tree(node, start, end, index, value):
    if end < index or index < start:
        return tree[node]
    if start == end:
        tree[node] = value
        return tree[node]
    mid = (start+end)//2
    tree[node] = (modify_tree(node*2, start, mid, index, value) + modify_tree(node*2+1, mid+1, end, index, value))
    return tree[node]
        
def cal_val(node, start, end, fs, fe):
    if end < fs or fe < start:
        return 0
    if fs <= start and end <= fe:
        return tree[node]
    mid = (start+end)//2
    return (cal_val(node*2, start, mid, fs, fe) + cal_val(node*2+1, mid+1, end, fs, fe))


for i in range(M):
    a, b, c = input().split()
    a, b, c = int(a), int(b), int(c)
    if a == 1:
        modify_tree(1, 0, N-1, b-1, c)
        num[b-1] = c
    else:
        if c < b:
            temp = c
            c = b
            b = temp
        print(int(cal_val(1, 0, N-1, b-1, c-1)))