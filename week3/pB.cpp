#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> letters;
    char c;
    while (cin >> c) {
        if (c == '<') {
            if (!letters.empty()) {
                letters.pop_back();
            }
        } else {
            letters.push_back(c);
        }
    }
    for (char x: letters) {
        cout << x;
    }
    cout << '\n';
}