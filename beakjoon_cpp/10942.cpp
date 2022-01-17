#include <iostream>
#include <algorithm>

using namespace std;


int N, M;
int numbers[2002] = {0,};
bool cash[2002][2002] = {0,};

int main(void){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> numbers[i];
    }
    cin >> M;

    for(int i = 1 ; i <=N ;i++){
        cash[i][i] = 1;
        if(numbers[i] == numbers[i+1]) cash[i][i+1] = 1;
    }

    for(int i = 1 ; i <=N ;i++){
        for(int j = 1 ; j+i <=N && i-j >0 ;j++){
            if(numbers[i-j] == numbers[i+j])
                cash[i-j][i+j] = 1;
            if(numbers[i-j] == numbers[i+1+j])
                cash[i-j][i+1+j] = 1;

        }
    }

    for(int i=0;i<M;i++){
        int S, E;
        cin >> S >> E;
        cout << cash[S][E] << "\n";
    }
    return 0;
}