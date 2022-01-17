A, B = input().split()
A, B = int(A), int(B)

def plus47(start, end, num):
    count = 0
    if end < num:
        return 0
    else:
        count += 1
        count += plus47(start, end, num*10+4)
        count += plus47(start, end, num*10+7)   
        return count

countA = plus47(0, B, 0)
countB = plus47(0, A-1, 0)
count = countA-countB
print(count)