#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int term[100001] = {0, };
int check[100001] = {0, };
int team = 1;
int loop_num = 0;
int ans = 0;
bool flag = 0;

void dfs(int n){
    if(n == term[n]){
        check[n] = team;
        flag = 1;
        return;
    }
    check[n] = team;
    if(check[term[n]] == 0)
        dfs(term[n]);
    else if(check[term[n]] == team){
        loop_num = term[n];
    }
    else{
        flag = 1;
    }
    if(flag){
        check[n] = -1;
        ans++;
    }
    if(n == loop_num){
        flag = 1;
    }
}

int main(void){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n;
        ans = 0;
        cin >> n;
        memset(term, 0, sizeof(term));
        memset(check, 0, sizeof(check));
        for(int j=1;j<=n;j++){
            cin >> term[j];
        }
        for(int j=1;j<=n;j++){
            if(check[j] == 0){
                flag = 0;
                loop_num = 0;
                dfs(j);
                team++;
            }
        }
        /*
        for(int j=1;j<=n;j++){
            if(check[j] == -1) ans++;
        }
        */
        cout << ans << endl;
    }
    return 0;
}