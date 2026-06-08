#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26, 0);

    for (char ch : magazine) {
        count[ch - 'a']++;
    }

    for (char ch : ransomNote) {
        if (count[ch - 'a'] == 0) {
            return false;
        }
        count[ch - 'a']--;
    }

    return true;
}

int main() {
    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    if (canConstruct(ransomNote, magazine)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}