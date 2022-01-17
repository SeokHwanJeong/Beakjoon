dic = [];
puzzle = [];
while(1):
    temp = input();
    if temp == "-":
        break;
    dic.append(temp);
while(1):
    temp = input();
    if temp == "#":
        break;
    puzzle.append(temp);

    
for i in puzzle:
    count = {};
    check = {};
    max_count = {};
    for j in i:
        check[j] = 0;
        count[j] = 0;
        if j in max_count:
            max_count[j] += 1;
        else:
            max_count[j] = 1;

    for j in dic:
        c = 0;
        t = True;
        for al in j:
            if al in check:
                check[al] += 1;
                c += 1;
        
        for key in check:
            if check[key] > max_count[key]:
                t = False;

        for key in check:
            if len(j) == c and t:
                if check[key] > 0:
                    count[key] += 1;
            check[key] = 0;
    
    min = count[i[0]];
    max = count[i[0]];
    mink = [];
    maxk = [];

    for key in count:
        if count[key] < min:
            min = count[key];
        if count[key] > max:
            max = count[key];
    for key in count:
        if count[key] == min:
            mink.append(key);
            #print(key, end='');
    for key in count:
        if count[key] == max:
            maxk.append(key);
    
    mink.sort();
    maxk.sort();

    for key in mink:
        print(key, end = "");
    print(" ", end = "");
    print(min, end = " ");
    for key in maxk:
        print(key, end = "");
    print(" ", end = "");
    print(max);