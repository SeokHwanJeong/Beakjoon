#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321;

using namespace std;

//int graph[1001][1001];
vector <pair<int, int>> graph[1001];
int N, M, X;

int dijkstra(int start, int dest){
    int near[1001];
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<=N;i++) near[i] = INF;
    near[start] = 0;
    pq.push(make_pair(0, start));
    
    for(;!pq.empty();){
        int min = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(current == dest){
            return min;
        }
        for(int j=0;j<graph[current].size();j++){
            int next_cur = graph[current][j].first;
            int next_val = graph[current][j].second;
            if(near[next_cur] > min+next_val){
                near[next_cur] = min+next_val;
                pq.push(make_pair(-near[next_cur], next_cur));
            }
        }
    }
    return near[dest];
}

int main(void){
    cin >> N >> M >> X;

    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    int max_val = 0;
    for(int i=1;i<=N;i++){
        int go = dijkstra(i, X);
        int back = dijkstra(X, i);
        if(max_val < go+back)
            max_val = go+back;

    }
    cout << max_val << endl;
    return 0;
}