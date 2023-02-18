#include <bits/stdc++.h>
using namespace std;

struct stck {
    int integer;
    string word;
    char letter;
    double decimal;
    stck *next, *prev;
    stck(int a) {
        integer = a;
        word = "";
        letter = '\0';
        decimal = INT_MIN;
        next = NULL;
        prev = NULL;
    }
    stck(char a) {
        integer = INT_MIN;
        word = "";
        letter = a;
        decimal = INT_MIN;
        next = NULL;
        prev = NULL;
    }
    stck(string a) {
        integer = INT_MIN;
        word = a;
        letter = '\0';
        decimal = INT_MIN;
        next = NULL;
        prev = NULL;
    }
    stck(double a) {
        integer = INT_MIN;
        word = "";
        letter = '\0';
        decimal = a;
        next = NULL;
        prev = NULL;
    }
};
void push(int a, stck*& p) {
    stck* tmp = new stck(a);
    tmp->prev = p;
    p->next = tmp;
    p = tmp;
}
void push(double a, stck*& p) {
    stck* tmp = new stck(a);
    tmp->prev = p;
    p->next = tmp;
    p = tmp;
}
void push(string a, stck*& p) {
    stck* tmp = new stck(a);
    tmp->prev = p;
    p->next = tmp;
    p = tmp;
}
void push(char a, stck*& p) {
    stck* tmp = new stck(a);
    tmp->prev = p;
    p->next = tmp;
    p = tmp;
}
void pop(stck*& p) {
    p = p->prev;
    p->next = NULL;
}
void check_stack(stck* p) {
    while (p != NULL) {
        if (p->integer != INT_MIN)
            cout << p->integer << " ";
        else if (p->word != "")
            cout << p->word << " ";
        else if (p->letter != '\0')
            cout << p->letter << " ";
        else
            cout << p->decimal << " ";
        p = p->next;
    }
}
int main() {
    stck *head = new stck(0), *temp = head;
    cout << "Pushing an integer in the stack\n";
    int h = 17;
    push(h, temp);
    cout << "Pushing a string in the stack\n";
    string s = "Arpit Pandey";
    push(s, temp);
    cout << "Pushing a character in the stack\n";
    char p = '@';
    push(p, temp);
    cout << "Pushing a double in the stack\n";
    double d = 2.356;
    push(d, temp);
    cout << "Checking elements of stack\n";
    check_stack(head->next);
    cout << "\n";
    cout << "Poping out the latest element\n";
    pop(temp);
    check_stack(head->next);
}
