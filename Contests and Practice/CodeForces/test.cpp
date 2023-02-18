#include<iostream>
#include<memory>
using namespace std;

class sol {
   public:
    sol() {
        cout << "Damn SON!" << endl;
    }

    ~sol() {
        cout << "UnDamn Son!!!!!!!!!!!!!!!" << endl;
    }
};
int main() {
    unique_ptr<sol> s(new sol());   
}