#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX = 100001;

int num[100001];
int dp[5][5][100001] = {0,};

int require_val(int start, int dest){
    if(start == 0) return 2;
    else if (start == dest) return 1;
    else if ( abs(start-dest) == 2) return 4;
    else return 3;
}

int solve(int left, int right, int step, int count){
    if(step==count) return 0;
    int cash = dp[left][right][step];
    if(cash != 0) return cash;
    dp[left][right][step] = min(require_val(left,num[step]) + solve(num[step], right, step+1, count), require_val(right,num[step]) + solve(left, num[step], step+1, count));
    return dp[left][right][step];
}

int main(void){
    int n;
    int count = 0;

    for(;cin>>n && n!=0;){
        num[count] = n;
        count++;
    }
    int ans = solve(0, 0, 0, count);
    cout << ans << endl;
}
