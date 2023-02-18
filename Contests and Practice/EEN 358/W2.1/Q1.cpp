#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    string name, address, mob_no, email;
    int mark, age;
    node* next;
    node() {
        next = NULL;
    }
    void show() {
        cout << "1)Name - " << name << endl
             << "2)address - " << address << endl
             << "3)Mobile Number - " << mob_no << endl
             << "4)email - " << email << endl
             << "5)Subject Marks - " << mark << endl
             << "6)age - " << age << endl;
    }
};

void t1(node* a) {
    cout << "\nDetails of the students\n";
    int i = 1;
    while (a) {
        cout << "S.no - " << i++ << endl;
        a->show();
        cout << endl;
        a = a->next;
    }
    system("pause");
}

void t2(node* t) {
    cout << "Enter the name of the student whose details to edit ";
    string nam;
    cin >> nam;
    while (t) {
        if (t->name == nam) {
            cout << "Student Found" << endl
                 << "Which value to change? Enter the S.no\n";
            t->show();
            int x;
            cin >> x;
            switch (x) {
                case 1:
                    cout << "Input New Name - ";
                    cin >> t->name;
                    break;
                case 2:
                    cout << "Input New Address - ";
                    cin >> t->address;
                    break;
                case 3:
                    cout << "Input New Mobile Number - ";
                    cin >> t->mob_no;
                    break;
                case 4:
                    cout << "Input New Email - ";
                    cin >> t->email;
                    break;
                case 5:
                    cout << "Input New Subject Marks - ";
                    cin >> t->mark;
                    break;
                case 6:
                    cout << "Input New age - ";
                    cin >> t->age;
                    break;
                default:
                    cout << "Invalid Input\n;";
            }
            system("pause");
            return;
        }
        t = t->next;
    }
    cout << "Student Entered Not Found!\n";
    system("pause");
}

void t3(node* a) {
    cout << "Enter the age above which Number of students to count ";
    int ag;
    cin >> ag;
    int ans = 0;
    while (a) {
        if (a->age > ag) ans++;
        a = a->next;
    }
    cout << "Number of students above age " << ag << " are " << ans << endl;
    system("pause");
}

void t4(node* a) {
    node* t = new node();
    cout << "Enter the following details - " << endl;
    cout << "1)Name - ";
    cin >> t->name;
    cout << "2)address - ";
    cin >> t->address;
    cout << "3)Mobile Number - ";
    cin >> t->mob_no;
    cout << "4)email - ";
    cin >> t->email;
    cout << "5)Subject Marks - ";
    cin >> t->mark;
    cout << "6)age - ";
    cin >> t->age;
    node* nxt = a->next;
    while (nxt) {
        if (nxt->name >= t->name) {
            a->next = t;
            t->next = nxt;
            cout << "Successfully Entered!\n";
            system("pause");
            return;
        }
        nxt = nxt->next;
        a = a->next;
    }
    a->next = t;
    cout << "Successfully Entered!\n";
    system("pause");
}

void t5(node* a) {
    cout << "Enter the name of the student To delete ";
    string nam;
    cin >> nam;
    node* nxt = a->next;
    while (nxt) {
        if (nxt->name == nam) {
            cout << "Student Found" << endl
                 << "Details of the student:\n";
            nxt->show();
            cout << "Delete? (1/0)";
            int x;
            cin >> x;
            if (x == 1) {
                a->next = nxt->next;
                cout << "Deleted!\n";
                system("pause");
                return;
            } else {
                cout << "Student NOT Deleted!\n";
                system("pause");
                return;
            }
        }
        a = a->next;
        nxt = nxt->next;
    }
    cout << "Student Entered Not Found!\n";
    system("pause");
}

void bsort(vector<pair<int, string>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].first > a[j].first)
                swap(a[i], a[j]);
        }
    }
}
void t6(node* a) {
    vector<pair<int, string>> v;
    while (a) {
        v.push_back(make_pair(a->mark, a->name));
        a = a->next;
    }
    bsort(v);
    int n = v.size();
    for (int i = n - 1; i >= 0; i--) {
        cout << "Name - " << v[i].second << " "
             << ", Marks - " << v[i].first << endl;
    }
    system("pause");
}

int main() {
    node* head = new node;
    head->name = "ROOT";
    while (1) {
        system("cls");
        cout << "Enter the operation you'd like to do\n";
        cout << "1) Show the contents of the list\n2) Edit the details of a specified student\n3) Count the number of students above a specified age\n4) Add a student\n5) Delete a student\n6) Show a merit list w.r.t marks they obtain\n7) Exit the program\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                t1(head->next);
                break;
            case 2:
                t2(head->next);
                break;
            case 3:
                t3(head->next);
                break;
            case 4:
                t4(head);
                break;
            case 5:
                t5(head);
                break;
            case 6:
                t6(head->next);
                break;
            default:
                return 0;
        }
    }
}