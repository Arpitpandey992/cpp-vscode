#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string INF_T_PostF(string s) {
    stack<char> st;
    string result;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}
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
    string infix = "4+3-3*(4+5)";
    cout << "Input  -> " << infix << endl;
    cout << "Result -> ";
    string postf = INF_T_PostF(infix);
    cout << PostFE_Value(postf);
}
