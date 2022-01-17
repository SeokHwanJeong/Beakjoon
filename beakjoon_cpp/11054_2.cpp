#include <iostream>
#include <algorithm>

using namespace std;

int suten[1000];
int up[1000]={0,};
int down[1000]={0,};

int main(void){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> suten[i];
    }
    
    for(int i=0;i<N;i++){
        up[i] = 1;
        down[N-i-1] = 1;
        for(int j=0;j<i;j++){
            if((suten[j] < suten[i])&&(up[i] < up[j]+1))
                up[i] = up[j]+1;
            if((suten[N-j-1] < suten[N-i-1])&&(down[N-i-1] < down[N-j-1]+1))
                down[N-i-1] = down[N-j-1]+1;
        }
    }
    
    int ans = 0;
    for(int i=0;i<N;i++){
        if(ans<up[i]+down[i]-1)
            ans = up[i]+down[i]-1;
    }
    
    cout << ans << endl;
}
