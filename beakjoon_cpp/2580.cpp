// 백트래킹

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <vector>

using namespace std;


int sudoku[9][9];
bool row_check[10][10] = {0, };
bool col_check[10][10] = {0, };
bool sq_check[10][10] = {0, };
vector<pair<int, int>> zero;
int zero_count = 0;
bool flag = false;

void fill_sudoku(int num);

int main(void){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sudoku[i][j];
            row_check[i][sudoku[i][j]-1] = true;
            col_check[j][sudoku[i][j]-1] = true;
            sq_check[(i/3)*3+(j/3)][sudoku[i][j]-1] = true;
        }
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j] == 0){
                zero.push_back(make_pair(i, j));
                zero_count++;
            }
        }
    }

    flag = false;
    fill_sudoku(0);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

void fill_sudoku(int num){
    if(num == zero_count){
        flag = true;
        return;
    }
    if(flag) return;
    int y = zero[num].first;
    int x = zero[num].second;

    for(int i=1;i<=9;i++){
        if(row_check[y][i-1]) continue;
        if(col_check[x][i-1]) continue;
        if(sq_check[(y/3)*3+(x/3)][i-1]) continue;

        row_check[y][i-1] = true;
        col_check[x][i-1] = true;
        sq_check[(y/3)*3+(x/3)][i-1] = true;
        sudoku[y][x] = i;
        fill_sudoku(num+1);
        if(flag) return;
        row_check[y][i-1] = false;
        col_check[x][i-1] = false;
        sq_check[(y/3)*3+(x/3)][i-1] = false;
        sudoku[y][x] = 0;

    }
}