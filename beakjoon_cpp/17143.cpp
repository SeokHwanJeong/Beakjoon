// 구현, 시뮬레이션

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;

int water[101][101]={0,};
//0:y, 1:X, 2:속력, 3:이동방향, 4:크기
int shark[10001][5] = {0,};
bool alive_shark[10001] = {0, };
int R, C, M;
int get_shark = 0;

void fishing(int j){
    for(int i = 1; i<=R;i++){
        if(water[i][j]){
            get_shark += shark[water[i][j]][4];
            alive_shark[water[i][j]] = false;
            water[i][j] = 0;
            break;
        }
    }
}
void moving(){
    for(int i=1;i<=M;i++){
        if(alive_shark[i]){
            if(shark[i][3] == 1){
                int temp_y = shark[i][0] - shark[i][2];
                while(temp_y < 1 || temp_y>R){
                    if(temp_y < 1){
                        shark[i][3] = 2;
                        temp_y = 2 - temp_y;
                    }
                    else if(temp_y>R){
                        shark[i][3] = 1;
                        temp_y = R - (temp_y-R);
                    }
                }
                shark[i][0] = temp_y;
            }
            else if(shark[i][3] == 2){
                int temp_y = shark[i][0] + shark[i][2];
                while(temp_y < 1 || temp_y>R){
                    if(temp_y < 1){
                        shark[i][3] = 2;
                        temp_y = 2 - temp_y;
                    }
                    else if(temp_y>R){
                        shark[i][3] = 1;
                        temp_y = R - (temp_y-R);
                    }
                }
                shark[i][0] = temp_y;
            }
            else if(shark[i][3] == 3){
                int temp_x = shark[i][1] + shark[i][2];
                while(temp_x < 1 || temp_x>C){
                    if(temp_x < 1){
                        shark[i][3] = 3;
                        temp_x = 2 - temp_x;
                    }
                    else if(temp_x>C){
                        shark[i][3] = 4;
                        temp_x = C - (temp_x-C);
                    }
                }
                shark[i][1] = temp_x;
            }
            else if(shark[i][3] == 4){
                int temp_x = shark[i][1] - shark[i][2];
                while(temp_x < 1 || temp_x>C){
                    if(temp_x < 1){
                        shark[i][3] = 3;
                        temp_x = 2 - temp_x;
                    }
                    else if(temp_x>C){
                        shark[i][3] = 4;
                        temp_x = C - (temp_x-C);
                    }
                }
                shark[i][1] = temp_x;
            }
        }
    }
}

void fighting(){
    memset(water, 0, sizeof(water));
    for(int i=1;i<=M;i++){
        if(alive_shark[i]){
            int y = shark[i][0];
            int x = shark[i][1];
            if(water[y][x] == 0){
                water[y][x] = i;
            }
            else{
                int another_shark = water[y][x];
                if(shark[another_shark][4] < shark[i][4]){
                    water[y][x] = i;
                    alive_shark[another_shark] = false;
                }
                else{
                    water[y][x] = another_shark;
                    alive_shark[i] = false;
                }
            }
        }
    }
}

int main(void){
    cin >> R >> C >> M;
    for(int i=1;i<=M;i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        water[r][c] = i;
        shark[i][0] = r;
        shark[i][1] = c;
        shark[i][2] = s;
        shark[i][3] = d;
        shark[i][4] = z;
        alive_shark[i] = true;
    }
    for(int i=1;i<=C;i++){
        fishing(i);
        moving();
        fighting();
    }
    cout << get_shark << endl;

}