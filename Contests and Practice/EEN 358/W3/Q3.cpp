#include <bits/stdc++.h>
using namespace std;

double PostFE_Value(string post_exp) {
    stack<double> stack;
    int len = post_exp.length();
    for (int i = 0; i < len; i++) {
        if (post_exp[i] >= '0' && post_exp[i] <= '9') {
            stack.push(post_exp[i] - '0');
        } else {
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();

            switch (post_exp[i]) {
                case '+':
                    stack.push(b + a);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(b * a);
                    break;
                case '/':
                    stack.push(b / a);
                    break;
                case '^':
                    stack.push(pow(b, a));
                    break;
            }
        }
    }
    return stack.top();
}
int main() {
    string s = "23+3/4-5/";  //(((2+3)/3)-4)/5
    cout << "Postfix Expression = " << s << endl;
    cout << "The Value of this expression is:\n";
    cout << PostFE_Value(s) << endl;
}
