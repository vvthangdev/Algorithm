//Vu Van Thang 20215643
//MSSV: 20215643
/*
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#
*/

#include <bits/stdc++.h>
using namespace std;

short hour, min, sec;
int time_to_sec(const string &time) {
    int hours, minutes, seconds;
    // sscanf(time.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
	
    return hours * 3600 + minutes * 60 + seconds;
}

bool check_phone_number(const string &num) {
	if (num.length() != 10) return false;
	for(char x : num) {
		if (!isdigit(x)) return false;
	}
	return true;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	map<string, int> number_calls_from;
	map<string, int> count_time_calls_from;
	bool check_phone_num = true;

	string type;
    int total_time = 0, time_duration = 0, number_total_calls = 0;
	while (true) {
		cin >> type;
		cin.ignore();
		if (type == "call") {
			string from_num, to_num, date;
			char from[10], to[10];
			cin >> from_num >> to_num >> date >> from >> to;
			if (check_phone_num == true) {
				if (!check_phone_number(from_num) && !check_phone_number(to_num)) check_phone_num = 0;
			}

			//cout << type << " " << from_num << " " << to_num << " " << date << " " << from << " " << to << "\n";
			time_duration = (time_to_sec(to) - time_to_sec(from));
			count_time_calls_from[from_num] += time_duration;
			total_time += time_duration;
			number_calls_from[from_num]++;
			number_total_calls++;
			// cout << total_time << endl;
		}
		else if (type == "#") break;
	}

	while (true) {
		string query; cin >> query;
		if (query == "#") break;
		else if (query == "?check_phone_number") {
		cout << check_phone_num << endl;
		}
		else if (query == "?number_calls_from") {
		string number; cin >> number;
		cout << number_calls_from[number] << endl;
		}
		else if (query == "?number_total_calls") {
		cout << number_total_calls << endl;
		}
		else if (query == "?count_time_calls_from") {
		string number; cin >> number;
		cout << count_time_calls_from[number] << endl;
		}
		
	}
	return 0;
}