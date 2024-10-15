//Vu Van Thang 20215643
//MSSV: 20215643
/*

*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2+3;
short n, cap, load;
int c[MAX][MAX];
int appear[MAX], x[MAX];
int f, f_best = INT_MAX, cmin = INT_MAX;

void input() {
	cin >> n >> cap;
	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j <= 2*n; j++) {
			cin >> c[i][j];
			if ((i != j) && cmin > c[i][j]) cmin = c[i][j];
		}
	}
}

int check(int v, int k) {
	if (appear[v] == 1) return 0;
	if (v > n) {
		if (!appear[v-n]) return 0;
	}
	else {
		if (load + 1 > cap) return 0;
	}
	return 1;
}

void solution() {
	if (f + c[x[2*n]][0] < f_best) {
		f_best = f + c[x[2*n]][0];
		for (int i = 0; i <= 2*n; i++) x_best[i] = x[i];
	}
}
void Try(int k) {
	for (int v = 1; v <= 2 * n; v++) {
		if(check(v, k)){
			x[k] = v;
			f += c[x[k-1]][x[k]];
			if (v <= n) load += 1; else load -= 1;
			appear[v] = 1;
			if (k == 2 * n) solution();
			else {
				if (f + (2 *n + 1 - k) * cmin < f_best)
				Try(k+1);
			} 
			if (v <= N) load -= 1; else load += 1;
			appear[v] = 0;
			f -= c[x[k-1]][x[k]];
		}
	}
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	Try(1);
	cout << f_best;
	return 0;
}
