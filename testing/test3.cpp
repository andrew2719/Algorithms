// FILEPATH: /e:/college/coding/programing/Algorithms/testing/test.cpp
#include <iostream>
#include <string>
#include <regex>
#include<bits/stdc++.h> 

using namespace std;

string generate_tac(string c_code) {
    vector<string> lines;
    string line;
    istringstream iss(c_code);
    while (getline(iss, line)) {
        lines.push_back(line);
    }

    vector<string> tac;
    int temp_counter = 0;

    auto new_temp = [&]() -> string {
        temp_counter += 1;
        return "t" + to_string(temp_counter);
    };

    bool inside_loop = false;

    for (auto& line : lines) {
        line = regex_replace(line, regex("^\\s+|\\s+$"), "");

        // Variable initialization (int a = 1;)
        smatch match;
        if (regex_match(line, match, regex("int (\\w+) *= *(\\d+);"))) {
            string var = match[1];
            string value = match[2];
            tac.push_back(var + " = " + value);
            continue;
        }

        // For loop start (for (int i = 1; i <= 10; i++))
        if (regex_match(line, match, regex("for \\(int (\\w+) *= *(\\d+); *\\w+ (<=|<|>|>=) *\\d+; *\\w+\\+\\+\\)"))) {
            string var = match[1];
            string init_value = match[2];
            tac.push_back(var + " = " + init_value);
            tac.push_back("L1:");
            inside_loop = true;
            continue;
        }

        // Inside for loop
        if (inside_loop) {
            // Condition check (i <= 10)
            if (regex_search(line, match, regex("(\\w+) (<=|<|>|>=) (\\d+)"))) {
                string var = match[1];
                string op = match[2];
                string value = match[3];
                tac.push_back("if not (" + var + " " + op + " " + value + ") goto L2");
                continue;
            }

            // Increment (i++)
            if (regex_search(line, match, regex("\\w+\\+\\+"))) {
                string var = match[1];
                tac.push_back(var + " = " + var + " + 1");
                tac.push_back("goto L1");
                inside_loop = false;
                continue;
            }

            // Inside loop assignments (a = a + 1)
            if (regex_match(line, match, regex("(\\w+) *= *(\\w+) *\\+ *(\\d+);"))) {
                string var = match[1];
                string expr_var = match[2];
                string value = match[3];
                string temp = new_temp();
                tac.push_back(temp + " = " + expr_var + " + " + value);
                tac.push_back(var + " = " + temp);
                continue;
            }
        }
    }

    tac.push_back("L2:");
    return accumulate(tac.begin(), tac.end(), string(""), [](string a, string b) { return a + b + "\n"; });
}

string c_code = R"(
#include <stdio.h>

int main() {
    int a = 1;
    for (int i = 1; i <= 10; i++) {
        a = a + 1;
    }
}
)";



int main() {
    cout << generate_tac(c_code) << endl;
}
