#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;

    string currentString = "";
    int currentNum = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            currentNum = currentNum * 10 + (ch - '0');
        }
        else if (ch == '[') {
            countStack.push(currentNum);
            stringStack.push(currentString);

            currentNum = 0;
            currentString = "";
        }
        else if (ch == ']') {
            int repeat = countStack.top();
            countStack.pop();

            string temp = currentString;

            currentString = stringStack.top();
            stringStack.pop();

            while (repeat--) {
                currentString += temp;
            }
        }
        else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    string s = "3[a]2[bc]";

    cout << decodeString(s);

    return 0;
}