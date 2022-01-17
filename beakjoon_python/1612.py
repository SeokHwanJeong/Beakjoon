N = int(input())

if N%2==0 or N%5==0:
    print(-1) 
else:
    temp = 1
    ans = 1
    flag = True
    while temp%N != 0:
        temp = temp%N
        temp = temp*10 + 1
        ans+=1
    print(ans)
