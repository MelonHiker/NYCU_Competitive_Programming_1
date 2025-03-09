#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stringstream ss;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin.ignore();
        map<string, set<string>> order;
        while (n--) {
            string line;
            getline(cin, line);
    
            ss << line;
            string name, food;
            ss >> name;
            while (ss >> food) {
                order[food].insert(name);
            }
            ss.str("");
            ss.clear();
        }

        for (auto pr: order) {
            cout << pr.first;
            for (auto name: pr.second) {
                cout << " " << name;
            }
            cout << '\n';
        }
        cout << '\n';
    }
}