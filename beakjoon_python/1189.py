R, C, K = input().split()
R, C, K = int(R), int(C), int(K);

load = []
check = []
for i in range(R):
    load.append(input())
    temp = []
    check.append(list(1 for i in range(C)))
check[R-1][0] = 0
ans = {}


def dfs(r, c, t):
    if r == 0 and c == C-1:
        if t in ans:
            ans[t] = ans[t]+1;
        else:
            ans[t] = 1;
        return;

    if r>0 and load[r-1][c] != 'T' and check[r-1][c]:
        check[r-1][c] = 0;
        dfs(r-1, c, t+1)
        check[r-1][c] = 1;

    if r<R-1 and load[r+1][c] != 'T' and check[r+1][c]:
        check[r+1][c] = 0;
        dfs(r+1, c, t+1)
        check[r+1][c] = 1;

    if c>0 and load[r][c-1] != 'T' and check[r][c-1]:
        check[r][c-1] = 0;
        dfs(r, c-1, t+1)
        check[r][c-1] = 1;

    if c<C-1 and load[r][c+1] != 'T' and check[r][c+1]:
        check[r][c+1] = 0;
        dfs(r, c+1, t+1)
        check[r][c+1] = 1;

dfs(R-1, 0, 1)
if K in ans:
    print(ans[K])
else:
    print(0)