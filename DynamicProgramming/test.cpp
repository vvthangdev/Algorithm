#include <bits/stdc++.h>
using namespace std;

int time_cal(int *from, int *to) {
    return 3600 * (to[0] - from[0]) + 60 * (to[1] - from[1]) + (to[2] - from[2]);
}

int is_valid_number(const string &number) {
    if (number.length() != 10) return 0;
    for (char c : number) {
        if (!isdigit(c)) return 0;
    }
    return 1;
}

void solve() {
    int check = 1, total = 0;
    map<string, int> number_of_calls;
    map<string, int> total_duration;
    vector<int> result;
    string type;

    // First loop to record the call data
    while (true) {
        cin >> type;
        if (type == "call") {
            string from, to;
            int yyyy, mm, dd;
            int time[2][3];
            cin >> from >> to;
            scanf("%d-%d-%d %d:%d:%d %d:%d:%d", &yyyy, &mm, &dd,
                  &time[0][0], &time[0][1], &time[0][2],
                  &time[1][0], &time[1][1], &time[1][2]);
//			cout << yyyy << " " << mm << " " << dd;
            number_of_calls[from]++;
            total_duration[from] += time_cal(time[0], time[1]);
            if (check == 1 && (!is_valid_number(from) || !is_valid_number(to))) {
                check = 0;
            }
            total++;
        } else if (type == "#") {
            break;
        }
    }

    // Second loop for processing queries
    while (true) {
        cin >> type;
        if (type == "?check_phone_number") {
            result.push_back(check);
        } else if (type == "?number_calls_from") {
            string from;
            cin >> from;
            result.push_back(number_of_calls[from]);
        } else if (type == "?count_time_calls_from") {
            string from;
            cin >> from;
            result.push_back(total_duration[from]);
        } else if (type == "?number_total_calls") {
            result.push_back(total);
        } else if (type == "#") {
            break;
        }
    }

    // Output all results
    for (int r : result) {
        cout << r << '\n';
    }
}

int main() {
    solve();
}
