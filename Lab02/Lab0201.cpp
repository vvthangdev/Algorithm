//Vu Van Thang 20215643
//MSSV: 20215643
/*
3 5
1 1 1
=>6
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int n, M, v;
vector<int> a;
int cnt = 0;
int t[MAX] = {0};
int f = 0;

void input() {
	cin >> n >> M;
	a.push_back(0);
	for (int i = 1; i <= n; i++){
		cin >> v;
		a.push_back(v);
		t[i] = t[i-1] + v;
	}
}

void Try(int k) {
	int u = (M - f - (t[n] - t[k]))/a[k];
	for(int v = 1; v <= u; v++) {
		f+= a[k] * v;
		if (k < n) Try(k + 1);
		else {
			if( f == M ) cnt++;
		}
		f -= a[k] * v; // backtracking
	}
}
void solve() {
	Try(1);
	cout << cnt;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();
	return 0;
}
