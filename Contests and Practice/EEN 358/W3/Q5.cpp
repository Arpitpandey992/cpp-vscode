#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return isdigit(c);
}

double PreFE_Value(string exprsn) {
    stack<double> Stack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {
        if (isOperand(exprsn[j]))
            Stack.push(exprsn[j] - '0');

        else {
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            switch (exprsn[j]) {
                case '+':
                    Stack.push(o1 + o2);
                    break;
                case '-':
                    Stack.push(o1 - o2);
                    break;
                case '*':
                    Stack.push(o1 * o2);
                    break;
                case '/':
                    Stack.push(o1 / o2);
                    break;
            }
        }
    }
    return Stack.top();
}

int main() {
    string s = "+4*35";  //4+(3*5)
    cout << "Prefix Expression = " << s << endl;
    cout << "The Value of this expression is:\n";
    cout << PreFE_Value(s) << endl;
}
