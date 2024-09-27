//Vu Van Thang 20215643
//MSSV: 20215643
/*
Day con tang dai nhat su dung quy hoach dong
9
10 20 2 5 3 8 8 25 6
-> 4
*/

#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> a(n);
//	Li: độ dài dãy con tăng dài nhất kết thúc ở chỉ số i
//Li = max (Li, Lj + 1) : a[i] > a[j]
	for (auto &x : a) {
		cin >> x;
	}
	vector<int> L(n, 1);
	
	for(auto i =0; i < a.size(); i++) {
		//duyet qua tung phan tu dung truoc chi so i
		for (auto j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}
	
	cout << *max_element(L.begin(), L.end()) << endl;
	return 0;	
}