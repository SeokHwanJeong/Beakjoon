#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
vector<int> graph[50001];
vector<int> tree_reverse[50001];
int parent[50001];
bool check[50001] = {0,};
int deep[50001] = {0, };

void make_tree(){
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    check[1] = 1;
    while(!q.empty()){
        int temp = q.front().first;
        int depth = q.front().second;
        q.pop();
        for(int i=0;i<graph[temp].size();i++){
            if(!check[graph[temp][i]]){
                q.push(make_pair(graph[temp][i], depth+1));
                //tree_reverse[graph[temp][i]].push_back(temp);
                parent[graph[temp][i]] = temp;
                check[graph[temp][i]] = 1;
                deep[graph[temp][i]] = depth+1;
            }
        }
    }
}

int find_node(int a, int b){
    while(a != b){
        if(deep[a] >= deep[b]){
            a = parent[a];
        }
        else if(deep[a] < deep[b]){
            b = parent[b];
        }
    }
    return a;
}

int main(void){
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    make_tree();
    cin >> M;
 
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        cout << find_node(a, b) << endl;
    }    
}