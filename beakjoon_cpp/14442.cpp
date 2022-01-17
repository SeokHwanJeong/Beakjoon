#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int wallmap[1000][1000];
bool check[1000][1000][10] = {0, };
int pl[2][4] = {{ 0, 0, 1, -1 }, { 1, -1, 0, 0 }};

void bfs(){
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 1, 0));
    check[0][0][0] = 1;

    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dep = get<2>(q.front());
        int left_one = get<3>(q.front());
        q.pop();

        if (y == N-1 && x == M-1){
            cout << dep << endl;
            return;
        }

        for(int i=0;i<4;i++){
            int ny = y + pl[0][i];
            int nx = x + pl[1][i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if(check[ny][nx][left_one] == 0){
                if(wallmap[ny][nx] == 0){
                    check[ny][nx][left_one] = 1;
                    q.push(make_tuple(ny, nx, dep+1, left_one));
                }
                else if(wallmap[ny][nx] == 1){
                    if(left_one < K){
                        check[ny][nx][left_one+1] = 1;
                        q.push(make_tuple(ny, nx, dep+1, left_one+1));
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}


int main(void){
    cin >> N >> M >> K;

    for(int i=0;i<N;i++){
        char temp[1001];
        cin >> temp;
        for(int j=0;j<M;j++){
            wallmap[i][j] = int(temp[j] - '0');
        }
    }
    bfs();


    return 0;
}