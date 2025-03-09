#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    auto ck = [&](int k) -> bool {
        vector<int> cnt1(26);
        for (int i = 0; i < k; i++) {
            cnt1[s[i] - 'a']++;
        }
        for (int i = k; i < s.size(); i+=k) {
            vector<int> cnt2(26);
            for (int j = i; j < i + k; j++) {
                cnt2[s[j] - 'a']++;
            }
            if (cnt1 != cnt2) {
                return false;
            }
        }
        return true;
    };
    for (int i = 1; i <= s.size() / 2; i++) {
        if (s.size() % i) {
            continue;
        }
        if (ck(i)) {
            cout << s.substr(0, i) << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}