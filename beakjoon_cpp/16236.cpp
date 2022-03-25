#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;

int sea[20][20];
bool check[20][20] = {0};
int N;
int consumed_time = 0;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

struct shark{
    int x;
    int y;
    int size;
    int count;
};
struct fish{
    int x;
    int y;
    int size;
    int time;
};
vector<fish> fish_zone;

shark baby;

int bfs(){
    bool flag = 1;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(baby.y, baby.x, 0));
    check[baby.y][baby.x] = 1;
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=N) continue;
            if(nx<0 || nx>=N) continue;

            if(sea[ny][nx] <= baby.size && check[ny][nx] == 0){
                if(sea[ny][nx] < baby.size && sea[ny][nx]!=0){
                    fish temp;
                    temp.y = ny;
                    temp.x = nx;
                    temp.time = t+1;
                    temp.size = sea[ny][nx];
                    fish_zone.push_back(temp);
                    flag = 0;
                }
                else{
                    q.push(make_tuple(ny, nx, t+1));
                    check[ny][nx] = 1;
                }
            }
        }
    }
    return flag;
}

bool cmp(fish a, fish b) { 
    if(a.time < b.time) return true;
    else if(a.time == b.time){
        if(a.y < b.y) return true;
        else if(a.y == b.y){
            if(a.x < b.x) return true;
        }
    }
    return false;
} 

int main(void){
    cin >> N;
    baby.size = 2;
    baby.count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> sea[i][j];
            if(sea[i][j] == 9){
                sea[i][j] = 0;
                baby.y = i;
                baby.x = j;
            }
        }
    }
    bool flag = 0;
    while(true){
        memset(check, 0, sizeof(check));
        if(baby.count >= baby.size){
            baby.size += 1;
            baby.count = 0;
        }
        flag = bfs();
        if(flag) break;
        std::sort(fish_zone.begin(), fish_zone.end(), cmp);
        fish cur = fish_zone.front();
        baby.y = cur.y;
        baby.x = cur.x;
        consumed_time += cur.time;
        baby.count++;
        sea[baby.y][baby.x] = 0;
        fish_zone.clear();
    }

    cout << consumed_time << endl;

    return 0;
}