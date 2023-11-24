#include <iostream>
#include <string>
using namespace std;

string input;
int pos = 0;

void error() {
    cout << "Error at position " << pos << endl;
    exit(0);
}

void match(char c) {
    if (input[pos] == c) {
        pos++;
    } else {
        error();
    }
}

void E();
void T();
void F();

void E() {
    T();
    while (input[pos] == '+') {
        match('+');
        T();
        cout << "E -> E + T" << endl;
    }
}

void T() {
    F();
    while (input[pos] == '*') {
        match('*');
        F();
        cout << "T -> T * F" << endl;
    }
}

void F() {
    if (input[pos] == '(') {
        match('(');
        E();
        match(')');
    } else if (isalpha(input[pos])) {
        match(input[pos]);
        cout << "F -> id" << endl;
    } else {
        error();
    }
}

int main() {
    cout << "Enter an expression: ";
    cin >> input;
    E();
    if (pos == input.length()) {
        cout << "Parsing successful!" << endl;
    } else {
        error();
    }
    return 0;
}
