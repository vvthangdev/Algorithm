#include <bits/stdc++.h>
using namespace std;

/*
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#
#
*/
int time_call;



map<string, int> calls_from;
map<string, int> count_time_from;

bool check_phone_num(string phone_num) {
    if (phone_num.length() != 10) return false;
    for(char c : phone_num) {
        if(!isdigit(c)) return false;
    }
    return true;
}

int main () {
    int check_phone_number = 1;
//    cout << check_phone_number;
    int total_calls = 0;
    string call;
    cin >> call;
    cin.ignore();
    while (call == "call") {
        string from_number, to_number;
        int year, month, day;
        int hour_from, min_from, sec_from;
        int hour_to, min_to, sec_to;
        
        cin >> from_number >> to_number;
        cin.ignore();
        scanf("%d-%d-%d %d:%d:%d %d:%d:%d",
              &year, &month, &day,
              &hour_from, &min_from, &sec_from,
              &hour_to, &min_to, &sec_to);
		calls_from[from_number]++;
		
		time_call = (hour_to - hour_from) * 3600
                        + (min_to - min_from) * 60
                        + (sec_to - sec_from);
        count_time_from[from_number] += time_call;
        
        if (check_phone_number == 1) {
            if (!check_phone_num(from_number) || !check_phone_num(to_number)) {
                check_phone_number = 0;
            }
        }
        total_calls++;  
        cin >> call;
    }
    
    string query;
    string phone;
    cin >> query;
    while (query != "#") {
        if (query == "?check_phone_number") {
            cout << check_phone_number << "\n";
        } 
        else if (query == "?number_calls_from") {
            cin >> phone;
            cout << calls_from[phone] << "\n";
        } 
        else if (query == "?number_total_calls") {
            cout << total_calls << "\n";
        } 
        else if (query == "?count_time_calls_from") {
            cin >> phone;
            cout << count_time_from[phone] << "\n";
        }
        cin >> query;
    }
    return 0;
}
