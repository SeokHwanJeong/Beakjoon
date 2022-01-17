#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M, T;
//vector<int> onepan[51];
int onepan[51][51];
int visit[51][51] = {0, };
int start_end[51][2];
int add_num[2][4] = {{-1, 1, 0, 0}, {0, 0, 1, -1}};
bool flag_avg = 1;
bool flag_zero = 0;

void PrintPan(){
    cout << "----------" << endl;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            cout << onepan[i][j] << " ";
        }
        cout << endl;
    }
}

void TurnPan(int x, int d, int k){
    if(d == 0){
        for(int i=x; i<=N; i+=x){
            int temp[51];
            memcpy(temp, onepan[i]+(M-k), sizeof(int)*k);
            memcpy(temp+k, onepan[i], sizeof(int)*(M-k));
            memcpy(onepan[i], temp, sizeof(temp));
        }
    }
    else{
        for(int i=x; i<=N; i+=x){
            int temp[51];
            memcpy(temp, onepan[i]+k, sizeof(int)*(M-k));
            memcpy(temp+(M-k), onepan[i], sizeof(int)*k);
            memcpy(onepan[i], temp, sizeof(temp));
        }
    }
}

void dfs(int y, int x){
    int ny, nx;
    visit[y][x] = 1;
    for(int i=0;i<4;i++){
        ny = y + add_num[0][i];
        nx = x + add_num[1][i];

        if(ny < 1 || ny > N) continue;
        if(nx < 0) nx = M-1;
        if(nx >= M) nx = 0;
        
        if(!visit[ny][nx] && onepan[y][x]==onepan[ny][nx] && onepan[ny][nx] > 0){
            visit[ny][nx] = 1;
            flag_zero = 1;
            dfs(ny, nx);
        }
    }
    if(flag_zero){
        onepan[y][x] = 0;
        flag_avg = 0;
    }
}

int sum(){
    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            ans += onepan[i][j];
        }
    }
    return ans;
}

float avgg(){
    float ans = 0;
    float c = 0;
    bool f = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if(onepan[i][j]){
                ans += onepan[i][j];
                c++;
                f = 1;
            }
        }
    }
    if(f) ans /= c;
    return ans;
}

int main(void){
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            cin >> onepan[i][j];
        }
    }
    for(int i=0;i<T;i++){
        int x, d, k;
        cin >> x >> d >> k;
        flag_avg = 1;
        TurnPan(x, d, k);
        memset(visit, 0, sizeof(visit));
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++){
                flag_zero = 0;
                if(!visit[i][j] && onepan[i][j] > 0){
                    dfs(i, j);
                }
            }
        }
        if(flag_avg){
            float avg = avgg();
            for(int i=1;i<=N;i++){
                for(int j=0;j<M;j++){
                    if(onepan[i][j] && onepan[i][j] < avg){
                        onepan[i][j] += 1;
                    }
                    else if(onepan[i][j] && onepan[i][j] > avg){
                        onepan[i][j] -= 1;
                    }
                }
            }
        }
    }
    cout << sum() << endl;

    return 0;
}