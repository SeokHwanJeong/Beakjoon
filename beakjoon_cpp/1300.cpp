#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long N, k;

long long cal(long long val){
    long long sum = 0;
    for(long long i=1;i<=N;i++){
        sum += min(N, val/i);
    }
    return sum;
}

void b_s(){
    long long start = 1, end = N*N;
    long long ret;
    while(start <= end){
        long long mid = (start+end) / 2;
        if(cal(mid) < k){
            start = mid+1;
        }
        else{
            ret = mid;
            end = mid-1;
        }
    }
    cout << ret << endl;
}
int main(void){
    cin >> N >> k;
    b_s();
    return 0;
}