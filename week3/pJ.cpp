#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<char> bl(n);
    for (auto &x: bl) {
        char b;
        cin >> b;
        x = b == 'T';
    }

    char c;
    vector<char> stk;
    while (cin >> c) {
        if (c == '*') {
            bool a = stk.back();
            stk.pop_back();
            bool b = stk.back();
            stk.pop_back();
            stk.push_back(a & b);
        } else if (c == '+') {
            bool a = stk.back();
            stk.pop_back();
            bool b = stk.back();
            stk.pop_back();
            stk.push_back(a | b);            
        } else if (c == '-') {
            bool a = stk.back();
            stk.pop_back();
            stk.push_back(!a);
        } else {
            stk.push_back(bl[c - 'A']);
        }
    }

    cout << "FT"[(int)stk.back()] << '\n';
}