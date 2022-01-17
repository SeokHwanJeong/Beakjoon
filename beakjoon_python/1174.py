N = int(input())
p_al = 1
flag = True

if N<1:
    print(-1)
elif N<11:
    print(N-1)
elif N > 1023:
    print(-1)
else:
    k = 11
    ans = 10
    while(k<N):
        if flag:
            ans +=1;
        else:
            ans = ans + (p_al-(ans%p_al))
        at = ans
        pre = -1
        alpha = 1
        p_al = 1
        flag = True
        while(at>0):
            t = at%10
            if pre >= t:
                flag = False
                p_al = alpha;
                tp = t;
            pre = t;
            alpha = alpha * 10;
            at //= 10
        if flag:
            k+=1;
    print(ans)


