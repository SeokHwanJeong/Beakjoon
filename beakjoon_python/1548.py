N = int(input())

num_list = input().split()
num_list = list(map(int, num_list))

num_list.sort()
if N < 3:
    max = N
else:
    max = 2
    for i in range(N-2):
        j = i+1
        temp = 0
        for k in range(N-1, j, -1):
            if num_list[i] + num_list[j] > num_list[k]:
                temp = k+1 - i
                if temp > max:
                    max = temp
                #print(max, i, j, k)

print(max)
    
