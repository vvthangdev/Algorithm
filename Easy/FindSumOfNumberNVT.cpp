//vvthangdev
/*

*/
#include <bits/stdc++.h>
using namespace std;
int sum = 0;

void inp(){
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }
}

int main () {
    inp();
    cout << sum;
    
    return 0;
}