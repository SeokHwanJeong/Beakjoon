N = int(input())

zero_one = []
for i in range(N):
    temp = input()
    zero_one.append(list(int(i) for i in temp))

def print_map(start_r, start_c, end_r, end_c):
    flag = 0
    isone = 0
    iszero = 0
    for i in range(start_r,end_r):
        for j in range(start_c,end_c):
            if zero_one[i][j] == 1:
                isone = 1
            else:
                iszero = 1
            if isone and iszero:
                flag = 1
                break
        if flag:
            break
    
    if isone and iszero:
        print("(", end="")
        print_map(start_r, start_c, start_r + (end_r-start_r)//2, start_c + (end_c-start_c)//2)
        print_map(start_r, start_c + (end_c-start_c)//2, start_r + (end_r-start_r)//2, end_c)
        print_map(start_r + (end_r-start_r)//2, start_c, end_r, start_c + (end_c-start_c)//2)
        print_map(start_r + (end_r-start_r)//2, start_c + (end_c-start_c)//2, end_r, end_c)
        print(")", end="")
    elif isone:
        print(1, end="")
    elif iszero:
        print(0, end="")

print_map(0, 0, N, N)