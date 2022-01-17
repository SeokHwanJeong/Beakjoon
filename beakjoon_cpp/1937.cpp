#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[500][500] = {0, };
int graph[500][500];
int next_move[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int N;

void print_dp(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int dfs(int i, int j){
    int max_val = 0;

    for(int l=0;l<4;l++){
        int next_i, next_j;
        next_i = i + next_move[0][l];
        next_j = j + next_move[1][l];
        if(next_i < 0 || next_i >=N || next_j < 0 || next_j >=N) continue;
        if(dp[next_i][next_j]){
            if(dp[next_i][next_j] > max_val && graph[i][j] < graph[next_i][next_j])
                max_val = dp[next_i][next_j];
            continue;
        }
        if(graph[i][j] < graph[next_i][next_j]){
            int temp = dfs(next_i, next_j);
            if(temp > max_val) max_val = temp;
        }
    }
    int ans = max_val + 1;
    dp[i][j] = ans;
    return ans;
}


int main(void){
    cin >> N;
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dp[i][j]){
                if(dp[i][j] > ans) ans = dp[i][j];
            }
            else{
                int temp = dfs(i, j);
                if(temp > ans) ans = temp;
            }
        }
    }
    cout << ans << endl;
}