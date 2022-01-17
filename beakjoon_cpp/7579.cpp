#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int memory[101] = {0,};
int ti[101] = {0,};
int dp[101][10001];

int main(void){
    cin >> N >> M;
    int ti_sum = 0;
    for(int i=1;i<=N;i++){
        cin >> memory[i];
    }
    for(int i=1;i<=N;i++){
        cin >> ti[i];
        ti_sum += ti[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<=ti_sum;j++){
            if(j-ti[i]>=0){
                dp[i][j] = dp[i-1][j-ti[i]] + memory[i];
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    for(int j=0;j<=ti_sum;j++){
        if(dp[N][j] >= M){
            cout << j << endl;
            break;
        }
    }
    return 0;
}
