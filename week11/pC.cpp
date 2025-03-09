#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    k--;
    string s(k / 25 + 2, '\0');
    for (int i = 0; i < s.size() - 1; i++) {
        if (i == 0 || s[i - 1] == 'z') {
            s[i] = 'a';
        } else {
            s[i] = 'z';
        }
    }
    k %= 25;
    if (s[s.size() - 2] == 'a') {
        s[s.size() - 1] = 'a' + k + 1;
    } else {
        s[s.size() - 1] = 'z' - k - 1;
    }

    if (s.size() & 1) {
        int d =  (s.back() - 'a') / 2;
        s[1] -= d;
        s.back() -= d * 2;
    } else if (s.size() > 2) {
        int d =  ('z' - s.back()) / 2;
        s[1] -= d;
        s.back() += d * 2;
    }
    cout << s << '\n';
}