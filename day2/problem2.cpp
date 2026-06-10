#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if (n > m) return false;

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    for (int i = 0; i < n; i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    if (count1 == count2) return true;

    for (int i = n; i < m; i++) {
        count2[s2[i] - 'a']++;
        count2[s2[i - n] - 'a']--;

        if (count1 == count2) {
            return true;
        }
    }

    return false;
}

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    if (checkInclusion(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}