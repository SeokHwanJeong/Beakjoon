// 백트래킹
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int p_count[6] = {0, 5, 5, 5, 5, 5};
bool board[10][10];
int ans = 26;
int using_paper = 0;
int one_count = 0;
bool the_end = 0;

int square(int y, int x, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!board[y+i][x+j]){
                return 0;
            }
        }
    }
    return size;
}
void erase(int y, int x, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[y+i][x+j] = 0;
            one_count--;
        }
    }
    // cout << "---------"<< endl;
    // cout << " 5 : " << p_count[5] << ", 4 : " << p_count[4] << ", 3 : " << p_count[3] << ", 2 : " << p_count[2] << ", 1 : " << p_count[1] << endl;
    // cout << "---------"<< endl;
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    using_paper++;
    p_count[size]--;
}
void write(int y, int x, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[y+i][x+j] = 1;
            one_count++;
        }
    }
    using_paper--;
    p_count[size]++;
}
void back(){
    if(one_count == 0){
        if(using_paper < ans){
            ans = using_paper;
        }
    }
    if(using_paper >= ans){ 
        return;}
    for(int k=5;k>0;k--){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(board[i][j] == 1){
                        int flag = square(i, j, k);
                        if(flag && p_count[flag]){
                            erase(i, j, k);
                            back();
                            write(i, j, k);
                        }
                }
            }
        }
    }
}

int main(void){

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            cin >> board[i][j];
            if(board[i][j]) one_count++;
        }
    
    back();

    if(ans == 26) ans = -1;
    cout << ans << endl;
    
    return 0;
}



