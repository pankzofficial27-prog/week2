#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    if (p.size() > s.size()) return result;

    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);

    for (int i = 0; i < p.size(); i++) {
        pCount[p[i] - 'a']++;
        sCount[s[i] - 'a']++;
    }

    if (pCount == sCount)
        result.push_back(0);

    for (int i = p.size(); i < s.size(); i++) {
        sCount[s[i] - 'a']++;
        sCount[s[i - p.size()] - 'a']--;

        if (pCount == sCount)
            result.push_back(i - p.size() + 1);
    }

    return result;
}

int main() {
    string s, p;

    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}