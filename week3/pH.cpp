#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<char> node = {'\0', '\0'};
    vector<int> nxt = {1, 1}, pre = {0, 0};
    int lp = 0, rp = 1;
    auto remove = [&]() -> void {
        if (!lp) {
            return;
        }
        nxt[pre[lp]] = rp;
        pre[rp] = pre[lp];
        lp = pre[rp];
    };
    auto add = [&](char c) -> void {
        node.push_back(c);
        int ni = node.size() - 1;
        nxt[lp] = ni;
        pre[rp] = ni;
        nxt.push_back(rp);
        pre.push_back(lp);
        lp = ni;
    };
    
    string s;
    getline(cin, s);
    for (auto c: s) {
        if (c == '<') {
            remove();
        } else if (c == '[') {
            lp = 0;
            rp = nxt[lp];
        } else if (c == ']') {
            rp = 1;
            lp = pre[rp];
        } else {
            add(c);
        }
    }
    for (lp = nxt[0]; lp != 1; lp = nxt[lp]) {
        cout << node[lp];
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
}