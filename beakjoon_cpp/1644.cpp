#include <iostream>
#include <algorithm>

using namespace std;

bool num[4000001] = {0, };
int prime_num[300000] = {0, };
int prime_count = 0;

void find_prime(int N){
    num[0]=1;
    num[1]=1;
    for(int i=2;i<=(N/2);i++){
        for(int j=2;i*j<=N;j++){
            if(i*j<=N)
                num[i*j]=1;
        }
    }

    for(int i=0;i<=N;i++){
        if(!num[i]){
            prime_num[prime_count] = i;
            prime_count++;
        }
    }
}

int main(void){
    int N;
    int ans = 0;
    cin >> N;

    find_prime(N);

    for(int i=0;i<prime_count;i++){
        int sum=0;
        for(int j=i;sum < N;j++){
            sum = sum + prime_num[j];
        }
        if(sum == N) ans++;
    }
    cout << ans << endl;

    return 0;
}