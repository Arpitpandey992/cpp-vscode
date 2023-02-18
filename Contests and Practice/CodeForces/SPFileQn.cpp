#include <bits/stdc++.h>
using namespace std;
struct fn {
    int empId;
    string empName;
    string jobTitle;
    int salary;
    int jobStart;
    int jobEnd;
};

int main() {
    fn obj1;

    vector<fn> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int empId, salary, jobStart, jobEnd;

        string empName, jobTitle;

        cin >> empId >> empName >> jobTitle >> salary >> jobStart >> jobEnd;

        v.push_back({empId, empName, jobTitle, salary, jobStart, jobEnd});
    }

    int cnt30000 = 0, time = 0, anstime;

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int mon = v[i].salary;

        if (mon >= 30000) {
            cnt30000++;
        }

        mx = max(mx, mon);

        int stime = v[i].jobStart, send = v[i].jobEnd;

        int inv = send - stime;

        anstime = max(inv, anstime);
    }

    string personame;

    int x = 0;

    for (int i = 0; i < n; i++) {
        int mon = v[i].salary;

        x = max(x, mon);

        if (x <= mx) {
            personame = v[i].empName;
        }
    }

    return 0;
}