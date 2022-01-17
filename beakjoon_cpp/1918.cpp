#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

char ch[100];
stack<char> oper;

void print_ch(){
    for(int i=0;i<(sizeof(ch)/sizeof(char));i++){
        if(ch[i] >= 'A' && ch[i] <= 'Z')
            cout << ch[i];
        else if(ch[i] == '*' || ch[i] == '/'){
            while(!oper.empty() && (oper.top() == '*' || oper.top() == '/')){
                cout << oper.top();
                oper.pop();
            }
            oper.push(ch[i]);
        }
        else if(ch[i] == '+' || ch[i] == '-'){
            while(!oper.empty() && oper.top() != '('){
                cout << oper.top();
                oper.pop();
            }
            oper.push(ch[i]);
        }
        else if(ch[i] == '('){
            oper.push(ch[i]);
        }
        else if(ch[i] == ')'){
            while(!oper.empty() && oper.top() != '('){
                cout << oper.top();
                oper.pop();
            }
            oper.pop();
        }
    }
    while(!oper.empty()){
        cout << oper.top();
        oper.pop();
    }
}

int main(void){
    cin >> ch;
    print_ch();
}