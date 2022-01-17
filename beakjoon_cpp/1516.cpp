#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> building[501];
vector<int> building1[501];
vector<int> building2[501];
queue<int> q;
//bool building[501][501];
int req_time[501] = {0,};
int dp_time[501] = {0,};
bool check[501] = {0,};
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
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> req_time[i];
        for(int temp;cin >> temp && temp != -1;){
            building[i].push_back(temp);
            building1[i].push_back(temp);
            building2[temp].push_back(i);
        }
    }
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
    for(int i=1;i<=N;i++){
        cout << dp_time[i] << endl;
    }
}