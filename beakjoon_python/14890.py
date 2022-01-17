N, L = input().split()
N, L = int(N), int(L)

road_map = []

def can_row_load(i):
    pre_val = road_map[i][0]
    flat_count = 1
    check = 0
    for j in range(1,N):
        diff = pre_val - road_map[i][j]
        if diff == 0:
            pre_val = road_map[i][j]
            flat_count += 1
            if check:
                if flat_count == L:
                    flat_count = 0
                    check = 0
            continue
        elif diff > 1 or diff < -1:
            return 0
        else:
            if diff > 0:
                if check and flat_count < L:
                    return 0
                flat_count = 1
                check = 1;
                if check:
                    if flat_count == L:
                        flat_count = 0
                        check = 0
            else:
                if flat_count < L:
                    return 0
                flat_count = 1
        pre_val = road_map[i][j]
    
    if check and flat_count < L:
        return 0

    #print("row", i)
    return 1;


def can_col_load(i):
    pre_val = road_map[0][i]
    flat_count = 1
    check = 0
    for j in range(1,N):
        diff = pre_val - road_map[j][i]
        if diff == 0:
            pre_val = road_map[j][i]
            flat_count += 1
            if check:
                if flat_count == L:
                    flat_count = 0
                    check = 0
        elif diff > 1 or diff < -1:
            return 0
        else:
            if diff > 0:
                if check and flat_count < L:
                    return 0
                flat_count = 1
                check = 1;
                if check:
                    if flat_count == L:
                        flat_count = 0
                        check = 0
            else:
                if flat_count < L:
                    return 0
                flat_count = 1
        pre_val = road_map[j][i]
    
    if check and flat_count < L:
        return 0

    #print("col", i)
    return 1;


for _ in range(N):
    temp = input().split()
    temp = list(map(int, temp))
    road_map.append(temp)
ans = 0
for i in range(N):
    ans += can_row_load(i)
    ans += can_col_load(i)

print(ans)
