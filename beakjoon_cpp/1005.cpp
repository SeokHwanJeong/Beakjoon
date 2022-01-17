#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> building[1001];
vector<int> building1[1001];
vector<int> building2[1001];
queue<int> q;
//bool building[501][501];
int req_time[1001] = {0,};
int dp_time[1001] = {0,};
bool check[1001] = {0,};
int N;

void find_q(){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=1;i<=N;i++){
            if(!check[i] && building1[i].empty()){
                q.push(i);
                check[i] = true;
                flag = true;
                for(auto iter = building2[i].begin(); iter != building2[i].end(); iter++){
                    for(auto j = building1[*iter].begin(); j != building1[*iter].end(); j++){
                        if(*j==i){
                            building1[*iter].erase(j);
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main(void){
    int t;
    cin >> t;
    for(int _=0 ; _<t ; _++){
        int K;
        cin >> N >> K;
        for(int i=1;i<=N;i++){
            cin >> req_time[i];
        }
        for(int i=1;i<=K;i++){
            int a, b;
            cin >> a >> b;
            building[b].push_back(a);
            building1[b].push_back(a);
            building2[a].push_back(b);
        }
        int W;
        cin >> W;
        find_q();
        for(;!q.empty();){
            int i = q.front();
            q.pop();
            int max_val = 0;
            for(auto iter = building[i].begin(); iter != building[i].end(); iter++){
                if(max_val < dp_time[*iter])
                    max_val = dp_time[*iter];
            }
            dp_time[i] = max_val + req_time[i];
        }
        cout << dp_time[W] << endl;

        for(int i=1;i<=N;i++){
            building[i].erase(building[i].begin(), building[i].end());
            building1[i].erase(building1[i].begin(), building1[i].end());
            building2[i].erase(building2[i].begin(), building2[i].end());
            dp_time[i] = 0;
            req_time[i] = 0;
            check[i] = false;
        }
    }
}