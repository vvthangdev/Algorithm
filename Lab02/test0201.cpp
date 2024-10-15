//Vu Van Thang 20215643
//MSSV: 20215643
/*

*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 103;
int n, M, v;
int cnt = 0;
int f = 0;
vector<int> a;
int s[MAX] = {0};

void input() {
	cin >> n >> M;
	a.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> v;
		a.push_back(v);
		s[i] = s[i-1] + v;
	}
//	
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
}

void Try(int k) {
	int maxXk = (M - f - (s[n] - s[k]))/a[k];
	cout << "Max Xk = " << maxXk << endl;
	for (int i = 1; i <= maxXk; i++) {
		f += a[k] * i;
		cout << "f = "<<f << endl;
		if ( k < n) Try(k + 1);
		else {
			if (f == M) {
				cnt++;
				cout << "cnt = " << cnt << endl;
			};
		}
		f -= a[k] * i;
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
