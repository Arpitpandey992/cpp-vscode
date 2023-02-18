#include <iostream>
using namespace std;

struct student {
    string name;
    string fatherName;
    string enrollmentNo;  //string because enr.no. can be larger than integer limit
    string specialization;
    string major;
    string minor;
    string bloodGroup;
    string homeAddress;
    string homeNo;
    string street;
    string city;
    string state;
    int pinCode;
    string statusCategory;
    string bhawan;
    string roomNo;
    int gateScore;
};
void OUT(student* s) {
    cout << "Name:" << s->name << endl;
    cout << "Father's Name:" << s->fatherName << endl;
    cout << "Enrollment No.:" << s->enrollmentNo << endl;
    cout << "Specialization:" << s->specialization << endl;
    cout << "Major(s):" << s->major << endl;
    cout << "Minor(s):" << s->minor << endl;
    cout << "Blood Group:" << s->bloodGroup << endl;
    cout << "Home Address:" << s->homeAddress << endl;
    cout << "House Number:" << s->homeNo << endl;
    cout << "Street:" << s->street << endl;
    cout << "City:" << s->city << endl;
    cout << "State:" << s->state << endl;
    cout << "Pin Code:" << s->pinCode << endl;
    cout << "Status Category:" << s->statusCategory << endl;
    cout << "Bhawan Alloted:" << s->bhawan << endl;
    cout << "Room Number:" << s->roomNo << endl;
    cout << "Gate Score:" << s->gateScore << endl;
}

int main() {
    student* obj = new student;
    obj->name = "Arpit";
    obj->fatherName = "Pradeep";
    obj->enrollmentNo = "19115032";
    obj->specialization = "B.Tech";
    obj->major = "Electrical Engineering";
    obj->minor = "DSA";
    obj->bloodGroup = "O+";
    obj->homeAddress = "AFS Gwalior";
    obj->homeNo = "SMQ 1044/2";
    obj->street = "AFS";
    obj->city = "Gwalior";
    obj->state = "Madhya Pradesh";
    obj->pinCode = 474020;
    obj->statusCategory = "General";
    obj->bhawan = "Rajendra Bhawan";
    obj->roomNo = "CF-162";
    obj->gateScore = 348;
    OUT(obj);
}
