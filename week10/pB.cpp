#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool is_vowel[26] = {};
    is_vowel[0] = is_vowel['E' - 'A'] = is_vowel['I' - 'A'] = is_vowel['O' - 'A'] = is_vowel['U' - 'A'] = true;

    string s;
    cin >> s;
    auto dfs = [&](auto self, int idx=0, int cc=0, int cv=0, bool L=false) -> ll {
        if (idx == s.size()) {
            return L;
        }
        if (s[idx] == '_') {
            ll sum = 0;
            if (cv < 2) {
                sum += self(self, idx + 1, 0, cv + 1, L) * 5;
            }
            if (cc < 2) {
                if (!L) {
                    sum += self(self, idx + 1, cc + 1, 0, L) * 20;
                    sum += self(self, idx + 1, cc + 1, 0, true);
                } else {
                    sum += self(self, idx + 1, cc + 1, 0, L) * 21;
                }
            }
            return sum;
        }
        if (is_vowel[s[idx] - 'A'] && cv < 2) {
            return self(self, idx + 1, 0, cv + 1, L);
        }
        if (!is_vowel[s[idx] - 'A'] && cc < 2) {
            return self(self, idx + 1, cc + 1, 0, L || (s[idx] == 'L'));
        }
        return 0;
    };
    cout << dfs(dfs) << '\n';
}