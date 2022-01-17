#include <iostream>
#include <algorithm>

using namespace std;

int N;
int inorder[100000];
int postorder[100000];

void preorder(int i_s, int i_e, int p_s, int p_e){
    if(i_s > i_e || p_s > p_e) return;

    cout << postorder[p_e] << " ";
    int root_i;
    for(int i=i_s;i<=i_e;i++){
        if(inorder[i] == postorder[p_e]){ root_i = i; break;}
    }
    int left_size = root_i - i_s;
    int right_size = i_e - root_i;
    
    preorder(i_s, root_i-1, p_s, p_s+left_size-1);
    preorder(root_i+1, i_e, p_s+left_size, p_e-1);
    return;
}

int main(void){
    cin >> N;
    for(int i = 0;i<N;i++) cin >> inorder[i];
    for(int i = 0;i<N;i++) cin >> postorder[i];
    preorder(0, N-1, 0, N-1);
    return 0;
}