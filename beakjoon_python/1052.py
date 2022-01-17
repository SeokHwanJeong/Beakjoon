N, K = input().split();
N, K = int(N), int(K);
bottle = 1;
left = [];
ans = 0;

while(N + len(left)>K):
    if N%2 == 0:
        N /= 2;
        bottle *= 2;
    else:
        if N!=1:
            left.append(bottle);
            N -= 1;
            N /= 2;
            bottle *= 2;
        elif N==1 and len(left)>1:
            if left[0] != left[1]:
                ans += left[1] - left[0];
            left[1] *= 2;
            left.pop(0);
        elif N==1 and len(left) == 1:
            if bottle > left[0]:
                ans += bottle - left[0];
            elif bottle < left[0]:
                ans += left[0] - bottle;
            left.pop(0);

print(ans);

