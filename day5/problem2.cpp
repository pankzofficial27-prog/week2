#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> bankSet(bank.begin(), bank.end());

    if (bankSet.find(endGene) == bankSet.end())
        return -1;

    queue<pair<string, int>> q;
    q.push(make_pair(startGene, 0));

    char genes[] = {'A', 'C', 'G', 'T'};

    while (!q.empty()) {
        string current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == endGene)
            return steps;

        for (int i = 0; i < 8; i++) {
            char original = current[i];

            for (int j = 0; j < 4; j++) {
                current[i] = genes[j];

                if (bankSet.find(current) != bankSet.end()) {
                    q.push(make_pair(current, steps + 1));
                    bankSet.erase(current);
                }
            }

            current[i] = original;
        }
    }

    return -1;
}

int main() {
    string startGene = "AACCGGTT";
    string endGene = "AACCGGTA";

    vector<string> bank;
    bank.push_back("AACCGGTA");

    cout << minMutation(startGene, endGene, bank);

    return 0;
}