#include <iostream>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string temp = s + s;
    temp = temp.substr(1, temp.size() - 2);

    return temp.find(s) != string::npos;
}

int main() {
    string s;
    cin >> s;

    if (repeatedSubstringPattern(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}