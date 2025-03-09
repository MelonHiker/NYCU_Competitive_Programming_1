#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != '0' || tolower(s[i + 1]) != 'x') {
                continue;
            }
            string num;
            num.push_back('0');
            num.push_back(s[i + 1]);
            i += 2;
            while (i < s.size() && (isdigit(s[i]) || tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')) {
                num.push_back(s[i]);
                i++;
            }
            cout << num << ' ' << stoll(num, nullptr, 16) << '\n';
        }
    }
}