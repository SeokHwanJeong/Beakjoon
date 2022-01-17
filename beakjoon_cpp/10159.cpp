#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define INF 987654321

using namespace std;

int graph[101][101] = {0, };
int numbers[101] = {0, };
bool check[101] = {0, };

void floyd(int N){
    for(int i = 0; i<N;i++){
        for(int j = 0; j<N;j++){
            for(int k = 0; k<N;k++){
                if(graph[j][i] == 1 && graph[i][k] == 1)
                    graph[j][k] = 1;
                if(graph[j][i] == 2 && graph[i][k] == 2)
                    graph[j][k] = 2;
            }
        }
    }
}

int main(void){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            graph[i][j] = INF;
            if(i==j) graph[i][j] = 0;
        }
    }

    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 2;
    }
    floyd(N);

    for(int i = 0; i<N;i++){
        int count = 0;
        for(int j = 0; j<N;j++){
            if(graph[i][j]==INF) count++;
        }
        cout << count << endl;
    }


}