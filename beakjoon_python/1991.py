N = int(input())

tree = []

for i in range(N):
    temp = input().split()
    temp2 =[]
    for j in temp:
        if j == ".":
            temp2.append(-1)    
        else:
            temp2.append(ord(j)-ord("A"))
    tree.append(temp2)

tree.sort()

def print_node(idx):
    if idx > -1:
        print(chr(idx+65), end="")

def preorder_traversal(node):
    if node > -1 :
        print_node(node)
        preorder_traversal(tree[node][1])
        preorder_traversal(tree[node][2])

def inorder_traversal(node):
    if node > -1 :
        inorder_traversal(tree[node][1])
        print_node(node)
        inorder_traversal(tree[node][2])

def postorder_traversal(node):
    if node > -1 :
        postorder_traversal(tree[node][1])
        postorder_traversal(tree[node][2])
        print_node(node)

preorder_traversal(0)
print()
inorder_traversal(0)
print()
postorder_traversal(0)



