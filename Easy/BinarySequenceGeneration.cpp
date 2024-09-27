//vvthangdev
/*

*/
#include <bits/stdc++.h>
using namespace std;
int n;
int X[100];

void inp(){
    cin >> n;
}

void oup(){
    for(int i = 1; i <= n; i++) {
        cout << X[i];
    }
    cout << '\n';
}

int Try(int i){
    for(int j = 0; j < 2; j++){
        X[i] = j;
        if(i == n) oup();
        else Try(i + 1);
    }
}
int main () {
    inp();
    Try(1);
    
    return 0;
}