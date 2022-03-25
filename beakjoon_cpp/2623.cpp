// 위상정렬
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int singer[1001] = {0,};
vector<int> ne[1001];
vector<int> ans;

int main(void){
    cin >> N >> M;

    for(int i=0;i<M;i++){
        int A;
        cin >> A;
        vector<int> v;
        for(int j=0;j<A;j++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        for(int j=0;j<A;j++){
            int temp = v[j];
            for(int k=j+1;k<A;k++){
                if(find(ne[temp].begin(), ne[temp].end(), v[k]) != v.end()){
                    ne[temp].push_back(v[k]);
                    singer[v[k]]++;
                }
            }
        }
    }
    bool flag = true;
    while(flag){
        int count = 0;
        for(int i=1;i<=N;i++){
            if(singer[i] == 0){
                ans.push_back(i);
                singer[i] = -1;
                for(int j=0;j<ne[i].size();j++){
                    singer[ne[i][j]]--;
                }
                count++;
            }
        }
        if(count == 0){
            for(int i=1;i<=N;i++){
                if(singer[i] != -1){
                    cout << 0 << endl;
                    return 0;
                }
            }
            flag = false;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
    return 0;
}
