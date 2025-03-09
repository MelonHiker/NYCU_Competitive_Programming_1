#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    int m;
    cin >> m;
    int mx = 0;
    vector<int> query(m);
    for (int i = 0; i < m; i++) {
        cin >> query[i];
        mx = max(mx, query[i]);
    }

    vector<ll> dp(mx + 1), last(mx + 1, -1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = value[i]; j <= mx; j++) {
            dp[j] += dp[j - value[i]];
            if (dp[j - value[i]] == 1) {
                last[j] = i;
            }
        }
    }
    for (int q: query) {
        if (dp[q] == 0) {
            cout << "Impossible\n";
        } else if (dp[q] > 1) {
            cout << "Ambiguous\n";
        } else {
            int item = last[q];
            vector<int> ans;
            while (item != -1) {
                ans.push_back(item);
                q -= value[item];
                item = last[q];
            }
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] + 1 << " \n"[i == 0];
            }
        }
    }
}