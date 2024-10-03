#include <bits/stdc++.h>
using namespace std;

// Function to check if the phone number is valid (i.e., exactly 10 digits)
bool check_phone_num(string phone_num) {
    if (phone_num.length() != 10) return false;
    for (int i = 0; i < 10; i++) {
        if (phone_num[i] > '9' || phone_num[i] < '0') return false;
    }
    return true;
}

int total_calls = 0;

int main() {
    map<string, int> calls_from;
    map<string, int> count_time_from;
    int check_phone_number = 1;  // 1 if all numbers are valid, 0 otherwise
    
    string call;
    cin >> call >> call;

    while (call == "call") {
        char from_number[15], to_number[15];
        int year, month, day, hour_from, hour_to, min_from, min_to, sec_from, sec_to;
        
        // Read the call details (phone numbers, date, and time)
        scanf("%s %s %d-%d-%d %d:%d:%d %d:%d:%d",
              from_number,
              to_number,
              &year, &month, &day,
              &hour_from, &min_from, &sec_from,
              &hour_to, &min_to, &sec_to);

        // Check if both phone numbers are valid
        if (check_phone_number == 1) {
            if (!check_phone_num(from_number) || !check_phone_num(to_number)) {
                check_phone_number = 0;  // Set to 0 if either number is invalid
            }
        }

        // Increment the call count from the "from_number"
        calls_from[from_number]++;
        total_calls++;

        // Calculate the call duration in seconds
        int time_call = (hour_to - hour_from) * 3600
                        + (min_to - min_from) * 60
                        + (sec_to - sec_from);

        // Add the duration to the total time from the "from_number"
        count_time_from[from_number] += time_call;

        // Read the next call
        cin >> call;
    }

    // Query processing
    string query;
    cin >> query;
    while (query != "#") {
        if (query == "?check_phone_number") {
            // Output if all phone numbers were valid
            cout << check_phone_number << "\n";
        } 
        else if (query == "?number_calls_from") {
            // Output the number of calls from a specific phone number
            string number;
            cin >> number;
            cout << calls_from[number] << "\n";
        } 
        else if (query == "?number_total_calls") {
            // Output the total number of calls
            cout << total_calls << "\n";
        } 
        else if (query == "?count_time_calls_from") {
            // Output the total duration of calls from a specific phone number
            string number;
            cin >> number;
            cout << count_time_from[number] << "\n";
        }
        cin >> query;
    }

    return 0;
}
