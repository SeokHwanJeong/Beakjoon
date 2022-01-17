#include <iostream>
#include <algorithm>

using namespace std;

int suten[1000];
int up[1000][1000]={0,};
int down[1000][1000]={0,};

int main(void){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> suten[i];
    }
    
    for(int i=0;i<N;i++){
        up[i][i] = 1;
        down[i][i] = 1;
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int max_val = 0;
            for(int k=i;k<j;k++){
                if((suten[k] < suten[j])&&(max_val < up[i][k]))
                    max_val = up[i][k];
            }
            if(max_val) up[i][j] = max_val+1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int max_val = 0;
            for(int k=i;k<j;k++){
                if((suten[N-k-1] < suten[N-j-1])&&(max_val < down[i][k]))
                    max_val = down[i][k];
                
            }
            if(max_val) down[i][j] = max_val+1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(down[i][j])
                down[i][j] = down[i][j]-1;
        }
    }
    
    int ans = 0;
    for(int i=0;i<N;i++){
        int max_val1 = 0;
        int max_val2 = 0;
        for(int j=0;j<=i;j++){
            if(max_val1 < up[j][i]) max_val1 = up[j][i];
            if(max_val2 < down[j][N-i-1]) max_val2 = down[j][N-i-1];
        }
        if(ans < max_val1 + max_val2)
            ans = max_val1 + max_val2;
    }

    cout << ans << endl;
}
