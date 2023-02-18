#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string INF_T_PostF(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();

    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            char_stack.push('(');

        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        } else {
            if (isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }

                } else {
                    while (getPriority(infix[i]) < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}
string INF_T_PreF(string infix) {
    int l = infix.size();
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = INF_T_PostF(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}
int main() {
    string exp = "a-b+(c-d)*(e^f-e*f)^(a-b*c+b*f-g)-g";
    cout << "Infix Expression : " << exp << endl;
    cout << "Postfix Expression : ";
    cout << INF_T_PreF(exp) << endl;
}
