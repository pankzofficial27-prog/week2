#include <iostream>
#include <vector>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    vector<int> count(26, 0);

    for (char ch : s) {
        count[ch - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "First unique character index: "
         << firstUniqChar(s) << endl;

    return 0;
}