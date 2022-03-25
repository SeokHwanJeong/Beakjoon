#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;


int main(void){
    long long i;
    long long min, max;
    cin >> min >> max;
    long long ans = max - min + 1; // 살펴봐야 하는 숫자의 갯수
    vector<bool> sieve(max - min + 1, false);
    for(i=2;i<=1000000 && i <= max;i++){
        long long st = min / (i*i);
        if(st * (i*i) < min) st = (st+1)*(i*i);
        else st *= (i*i);
        long long sq = (i*i);
        while(st <= max){
            if(sieve[st-min] == 0){
                sieve[st-min] = 1;
                ans -= 1;
            }
            st += sq;
        }
        
    }
    cout << ans;
}