// 이분탐색, 두 포인터, 중간에서 만나기
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int num[4][4000];
int n;
long long ans = 0;
vector<int> ab;
vector<int> cd;

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[0][i] >> num[1][i] >> num[2][i] >> num[3][i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ab.push_back(num[0][i] + num[1][j]);
            cd.push_back(num[2][i] + num[3][j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    for(int i=0;i<ab.size();i++){
        int start = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        int end = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();

        ans += (end-start);
    }
    cout << ans << endl;
    return 0;
}
