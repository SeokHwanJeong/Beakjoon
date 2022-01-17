#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

int N;
int numbers[1001] = {0, };
int weight = 1;

int main(void){
    cin >> N;
    
    for(int i=0;i<N;i++){
    	cin >> numbers[i];
	}
	sort(numbers, numbers+N);
    if(numbers[0]!=1){
        cout<<1<<endl;
        return 0;
    }
    else{
        for(int i=1;i<N;i++){
            if(weight+1 < numbers[i]){
                cout << weight+1 << endl;
                return 0;
            }
            else{
                weight += numbers[i];
            }
        }
    }
    cout << weight+1 << endl;
    return 0;
}