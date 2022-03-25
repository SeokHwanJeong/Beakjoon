import sys
from typing import DefaultDict
input = sys.stdin.readline

MOD = 1000000007

N, M, K = input().split()
N, M, K = int(N), int(M), int(K)

num = []
tree = [0] * 4000000
for i in range(N):
    num.append(int(input()))
    
def fill_tree(node, start, end):
    if start==end:
        tree[node] = num[start]
        return num[start]
    mid = (start + end)//2
    tree[node] = ((fill_tree(node*2, start, mid)) * (fill_tree(node*2+1, mid + 1, end)))%MOD
    return tree[node]

def modify_tree(node, start, end, index, value):
    if end < index or index < start:
        return tree[node]
    if start == end:
        tree[node] = value
        return tree[node]
    mid = (start+end)//2
    tree[node] = (modify_tree(node*2, start, mid, index, value) * modify_tree(node*2+1, mid+1, end, index, value))%MOD
    return tree[node]
        
def cal_val(node, start, end, fs, fe):
    if end < fs or fe < start:
        return 1
    if fs <= start and end <= fe:
        return tree[node]
    mid = (start+end)//2
    return (cal_val(node*2, start, mid, fs, fe) * cal_val(node*2+1, mid+1, end, fs, fe))%MOD
    
    
fill_tree(1, 0, N-1)

for i in range(M+K):
    a, b, c = input().split()
    a, b, c = int(a), int(b), int(c)
    
    if a == 1:
        modify_tree(1, 0, N-1, b-1, c)
        num[b-1] = c
    else:
        print(int(cal_val(1, 0, N-1, b-1, c-1)%MOD))