#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}