a, b = input().split();
a = int(a);
b = int(b);
des = b-a;

count = 0;
possible_dis = 0;

while possible_dis < des:
    count+=1;
    if count%2==0:
        possible_dis = possible_dis + (count/2);
    else:
        possible_dis = possible_dis + (count//2)+1;
    
print(count);