N, r, c = input().split();
N, r, c = int(N), int(r), int(c);

def re(Ni, ri, ci):
    if Ni == 1:
        return ri*2 + ci;
    else:
        alpha = 0;
        temp = (2**(Ni-1));
        if(ri>=temp):
            ri = ri - temp;
            alpha += 2*(temp*temp);
        if(ci>=temp):
            ci = ci - temp;
            alpha += (temp*temp);
        return alpha + re(Ni-1, ri, ci);

print(re(N,r,c));

