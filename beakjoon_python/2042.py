import sys
from typing import DefaultDict
input = sys.stdin.readline

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
    mid = int((start + end)/2)
    tree[node] = fill_tree(node*2, start, mid) + fill_tree(node*2+1, mid + 1, end)
    return tree[node];

def modify_tree(node, start, end, index, value):
    if index < start or end < index:
        return
    
    tree[node] += value
    if start == end:
        return    
    
    mid = int((start+end)/2)
    if index <= mid:
        modify_tree(node*2, start, mid, index, value)
    else:
        modify_tree(node*2+1, mid+1, end, index, value)
        
def cal_val(node, start, end, fs, fe):
    if end < fs or fe < start:
        return 0
    if fs <= start and end <= fe:
        return tree[node]
    mid = int((start+end)/2)
    return cal_val(node*2, start, mid, fs, fe) + cal_val(node*2+1, mid+1, end, fs, fe)
    
    
fill_tree(1, 0, N-1)

for i in range(M+K):
    a, b, c = input().split()
    a, b, c = int(a), int(b), int(c)
    
    if a == 1:
        dif = c - num[b-1]
        modify_tree(1, 0, N-1, b-1, dif)
        num[b-1] = c
    else:
        print(cal_val(1, 0, N-1, b-1, c-1))