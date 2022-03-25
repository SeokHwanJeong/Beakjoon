// 자료구조, 분리집합
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;

int set[1000001];
int n, m;

int get_parent(int num){
    if(set[num] == num) return num;
    else return get_parent(set[num]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<=n;i++)
        set[i] = i;
    
    for(int i=0;i<m;i++){
        int mode, a, b;
        cin >> mode >> a >> b;
        if(mode == 0){
            int temp_a = get_parent(a);
            int temp_b = get_parent(b);
            if(temp_a < temp_b) set[temp_a] = temp_b;
            else set[temp_b] = temp_a;
        }
        else{
            int temp_a = get_parent(a);
            int temp_b = get_parent(b);
            if(temp_a == temp_b) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
