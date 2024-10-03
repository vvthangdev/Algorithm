#include <bits/stdc++.h>
using namespace std;

short hour, min, sec;

// Function to convert time in "HH:MM:SS" format to total seconds
int time_to_sec(const string &time) {
    sscanf(time.c_str(), "%d:%d:%d", &hour, &min, &sec);
    return hour * 3600 + min * 60 + sec;
}

// Function to check if a phone number is valid (10 digits, all numeric)
bool check_phone_number(const string &num) {
    if (num.length() != 10) return false;
    for (char x : num) {
        if (!isdigit(x)) return false;
    }
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> num_of_calls;  // to store the number of calls from each number
    map<string, int> total_duration; // to store the total duration of calls for each number
    bool check_phone_num = true;    // flag to check phone numbers
    
    string call;
    
    while (cin >> call && call == "call") {
        string from_num, to_num, date, start_time, end_time;
        cin >> from_num >> to_num >> date >> start_time >> end_time;
        
        // Check phone numbers
        if (!check_phone_number(from_num) || !check_phone_number(to_num)) {
            check_phone_num = false;
        }
        
        // Calculate the duration of the call in seconds
        int call_duration = time_to_sec(end_time) - time_to_sec(start_time);
        
        // Update the call count and total duration for the 'from_num'
        num_of_calls[from_num]++;
        total_duration[from_num] += call_duration;
    }
    
    // Query handling
    string query;
    while (cin >> query) {
        if (query == "?check_phone_number") {
            cout << (check_phone_num ? "YES" : "NO") << endl;
        } else if (query == "?number_calls_from") {
            string number;
            cin >> number;
            cout << num_of_calls[number] << endl;
        } else if (query == "?number_total_calls") {
            int total_calls = 0;
            for (const auto &entry : num_of_calls) {
                total_calls += entry.second;
            }
            cout << total_calls << endl;
        } else if (query == "?count_time_calls_from") {
            string number;
            cin >> number;
            cout << total_duration[number] << endl;
        }
    }

    return 0;
}
