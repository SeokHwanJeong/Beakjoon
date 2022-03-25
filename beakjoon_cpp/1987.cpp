#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int A = 65;
int R, C;
char board[21][21];
int alpha[26] = {0,};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int max_val = 0;

void dfs(int x, int y, int count);

int main(void){
    cin >> R >> C;
    for(int i = 0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 1);
    cout << max_val << endl;

    return 0;
}

void dfs(int y, int x, int count){
    if(count > max_val) max_val = count;
    alpha[int(board[y][x])-A] = 1;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=R) continue;
        if(nx<0 || nx>=C) continue;

        if(alpha[int(board[ny][nx])-A] == 0){
            dfs(ny, nx, count+1);
        }
    }
    alpha[int(board[y][x])-A] = 0;
}
