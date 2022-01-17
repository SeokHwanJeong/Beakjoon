N = int(input())
house_color = [];

for i in range(N):
    temp = input().split();
    house_color.append(list(map(int, temp)))

an = house_color[0][0]
bn = house_color[0][1]
cn = house_color[0][2]

for i in range(1,N):
    anm = house_color[i][0]+bn if house_color[i][0]+bn < house_color[i][0]+cn else house_color[i][0]+cn
    bnm = house_color[i][1]+an if house_color[i][1]+an < house_color[i][1]+cn else house_color[i][1]+cn
    cnm = house_color[i][2]+an if house_color[i][2]+an < house_color[i][2]+bn else house_color[i][2]+bn
    an = anm
    bn = bnm
    cn = cnm

ans = an if an<bn else bn
ans = ans if ans<cn else cn
print(ans)