txt = input()
tlist = []
for i in txt:
    tlist.append(i)

temp1 = tlist[:]
idx = 0;
ans = 0;

for i in tlist:
    temp2 = temp1[:]
    temp2.reverse()
    if temp1 == temp2:
        break;
    if idx == 0:
        temp1.append(i)
    else:
        temp1.insert(idx, i)
    idx -= 1;
    ans += 1;


print(len(txt)+ans)