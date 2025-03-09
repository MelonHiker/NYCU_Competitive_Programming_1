#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);
    stack<char> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(') {
                cout << s[i] << ' ' << i << '\n';
                return 0;
            }
            stk.pop();
        } else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[') {
                cout << s[i] << ' ' << i << '\n';
                return 0;
            }
            stk.pop();
        } else if (s[i] == '}') {
            if (stk.empty() || stk.top() != '{') {
                cout << s[i] << ' ' << i << '\n';
                return 0;
            }
            stk.pop();
        } else if (s[i] == '(' || s[i] == '[' || s[i] =='{') {
            stk.push(s[i]);
        }
    }
    cout << "ok so far\n";
}