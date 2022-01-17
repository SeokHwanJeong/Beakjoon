#include <iostream>
using namespace std;

int cash[501][501] = {0,};
int mat[501][2] = {0,};

int matcal(int start, int end){
    if(start==end){
        return 0;
    }
    if(cash[start][end]!=0)
        return cash[start][end];
    if(end-start == 1){
        cash[start][end] = mat[start][0]*mat[start][1]*mat[end][1];
        return mat[start][0]*mat[start][1]*mat[end][1];
    }
    int min = 2147483647;
    int temp;
    for(int i =start;i<end;i++){
        temp = matcal(start, i) + matcal(i+1, end) + mat[start][0]*mat[i][1]*mat[end][1];
        if(min > temp)
            min=temp;
    }
    cash[start][end] = min;
    return min;
}

int main(void){
    int N;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> mat[i][0] >> mat[i][1];
    }
    cout << matcal(0, N-1) << endl;
    
}