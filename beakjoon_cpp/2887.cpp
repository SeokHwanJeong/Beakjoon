#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> p;
typedef tuple<int, int, int> co;

int v;
//int coor[100000][3];
vector<co> coor;
vector<p> adj[100000];
bool visit[100000];

struct compare{
    bool operator()(p a, p b){
        return a.second > b.second;
    }
};

int Prim(){
    priority_queue<p, vector<p>, compare> pque;
    int ret = 0;
    for(int i = 0; i<adj[1].size();i++) pque.push(adj[0][i]);
    visit[0] = true;

    int cnt = 0;
    while(cnt<v-1){
        p curline = pque.top();
        pque.pop();

        int node = curline.first;
        int weight = curline.second;

        if(visit[node]) continue;
        visit[node] = true;
        cnt++;
        ret += weight;
        for(int i = 0;i < adj[node].size();i++){
            int nextnode = adj[node][i].first;
            if (!visit[nextnode]) pque.push(adj[node][i]);
        }
    }
    return ret;
}

int main(void){
    cin >> v;
    for(int i=0;i<v;i++){
        int x, y, z;
        cin >> x >> y >> z;
        coor.push_back({x, y, z});
    }
    for(int i=0;i<v;i++){
        for(int j=i+1;j<v;j++){
            int x_dif = abs(get<0>(coor[i])-get<0>(coor[j]));
            int y_dif = abs(get<1>(coor[i])-get<1>(coor[j]));
            int z_dif = abs(get<2>(coor[i])-get<2>(coor[j]));
            int min_val = (x_dif < y_dif) ? x_dif : y_dif;
            min_val = (min_val < z_dif) ? min_val : z_dif;

            adj[i].push_back({j, min_val});
            adj[j].push_back({i, min_val});
        }
    }

    cout << Prim() << endl;
    return 0;
}